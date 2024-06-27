/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gooey.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:45:54 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/1 23:07:23 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	kill_win(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	fdf->mlx.win_ptr = NULL;
	return (0);
}

void	gui_info(t_fdf fdf)
{
	void	*disp;
	void	*win;
	int		x;
	int		y;

	x = WINDOW_WIDTH - 270;
	y = 20;
	disp = fdf.mlx.mlx_ptr;
	win = fdf.mlx.win_ptr;
	mlx_string_put(disp, win, x + 20, y, WHITE, "Controls :");
	mlx_string_put(disp, win, x, y + 30, WHITE, "Move                < ^ v >");
	mlx_string_put(disp, win, x, y + 55, WHITE, \
		"Lower height            L_ctrl, L_shift");
	mlx_string_put(disp, win, x, y + 80, WHITE, \
		"Raise height            R_ctrl, R_shift");
	mlx_string_put(disp, win, x, y + 105, WHITE, "Zoom                +, -");
	mlx_string_put(disp, win, x, y + 130, WHITE, \
		"Toggle distortion                Space");
	mlx_string_put(disp, win, x, y + 145, WHITE, "reset                Return");
	if (fdf.to_scale)
		mlx_string_put(disp, win, x, y + 160, WHITE, \
			"height :                to scale");
	else
		mlx_string_put(disp, win, x, y + 160, WHITE, \
			"height :                distorted");
}

void	handle_input2(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Right)
		fdf->x_offset += 50;
	if (keysym == XK_Left)
		fdf->x_offset -= 50;
	if (keysym == XK_Up)
		fdf->y_offset -= 50;
	if (keysym == XK_Down)
		fdf->y_offset += 50;
	if (keysym == XK_Control_R)
		fdf->h_dist += 0.1;
	if (keysym == XK_Control_L)
		fdf->h_dist -= 0.1;
	if (keysym == XK_Shift_R)
		fdf->h_dist += 10;
	if (keysym == XK_Shift_L)
		fdf->h_dist -= 10;
}

int	handle_input(int keysym, t_fdf *fdf)
{
	handle_input2(keysym, fdf);
	if (keysym == XK_KP_Add)
	{
		fdf->zoom *= 1.1;
		compute_offsets(fdf);
	}
	if (keysym == XK_KP_Subtract)
	{
		fdf->zoom *= 0.9;
		compute_offsets(fdf);
	}
	if (keysym == XK_space)
	{
		fdf->to_scale++;
		if (fdf->to_scale == 2)
			fdf->to_scale = 0;
		compute_offsets(fdf);
	}
	if (keysym == XK_Return)
		setup_default(fdf);
	if (keysym == XK_Escape)
		return (kill_win(fdf));
	return (0);
}
