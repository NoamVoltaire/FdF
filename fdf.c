/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:45:54 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/1 23:07:23 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else if (pixel != NULL)
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int			i;
	int			j;
	t_segment	segment;

	segment.start = 0;
	segment.end = WINDOW_HEIGHT + WINDOW_WIDTH;
	segment.st_col = 0x0b4746;
	segment.end_col = color;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j, i, color_this_pxl(i + j, segment));
			j++;
		}
		++i;
	}
}

void	drawing_routine(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < fdf->mapdata.width)
	{
		i = 0;
		if (j == fdf->mapdata.width - 1)
		{
			while (i < fdf->mapdata.height -1)
			{
				edge_draw(fdf, i, j);
				i++;
			}
		}
		while (i < fdf->mapdata.height -1 && j < fdf->mapdata.width -1)
		{
			corner_draw(fdf, i, j);
			i++;
		}
		if (j < fdf->mapdata.width - 1)
			corner_draw_two(fdf, i, j);
		j++;
	}
}

int	render(t_fdf *fdf)
{
	if (fdf->mlx.win_ptr == NULL)
		return (1);
	render_background(&fdf->mlx.img, 0x470b21);
	drawing_routine(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, \
		fdf->mlx.img.mlx_img, 0, 0);
	gui_info(*fdf);
	return (0);
}

int	pop_the_window(t_fdf *fdf)
{
	fdf->mlx.mlx_ptr = mlx_init();
	if (fdf->mlx.mlx_ptr == NULL)
		return (MLX_ERROR);
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Fdf - A wireframe 3D mesh");
	if (fdf->mlx.win_ptr == NULL)
	{
		free(fdf->mlx.win_ptr);
		return (MLX_ERROR);
	}
	fdf->mlx.img.mlx_img = mlx_new_image \
		(fdf->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->mlx.img.addr = mlx_get_data_addr \
		(fdf->mlx.img.mlx_img, &fdf->mlx.img.bpp, \
			&fdf->mlx.img.line_len, &fdf->mlx.img.endian);
	mlx_loop_hook(fdf->mlx.mlx_ptr, &render, fdf);
	mlx_hook(fdf->mlx.win_ptr, 33, 131072, &kill_win, &fdf->mlx);
	mlx_key_hook(fdf->mlx.win_ptr, &handle_input, &fdf->mlx);
	mlx_loop(fdf->mlx.mlx_ptr);
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->mlx.img.mlx_img);
	mlx_destroy_display(fdf->mlx.mlx_ptr);
	free(fdf->mlx.mlx_ptr);
	return (0);
}
