/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 07:51:05 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/12 03:10:18 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_point	space_2_iso_plan(t_fdf fdf, t_mapdata *mapdata, int i, int j)
{
	t_point	ret;
	double	z;

	z = mapdata->map[i][j];
	if (mapdata->has_color)
		ret.color = mapdata->colors[i][j];
	else
		ret.color = z_dependant_color(mapdata, mapdata->map[i][j]);
	if (!fdf.to_scale)
	{
		if (mapdata->peak - mapdata->valley)
			z = z / (mapdata->peak - mapdata->valley);
		z *= fdf.h_dist;
	}
	ret.x = ((double)j - (double)i) * cos(0.523599);
	ret.y = (((double)j + (double) i) * sin(0.523599) - (double)z);
	ret.x *= fdf.zoom;
	ret.x += fdf.x_offset;
	ret.y *= fdf.zoom;
	ret.y += fdf.y_offset;
	return (ret);
}

int	vertical(t_img *img, t_point from, t_point towards)
{
	int			i;
	t_segment	segment;

	segment.start = (int)from.y;
	segment.end = (int)towards.y;
	segment.st_col = from.color;
	segment.end_col = towards.color;
	if (from.y > towards.y)
		return (vertical(img, towards, from));
	i = (int)from.y;
	while (i < (int)towards.y)
	{
		if (within_bounds((int)from.x, (int)i))
			img_pix_put(img, (int)from.x, (int)i, color_this_pxl(i, segment));
		i++;
	}
	return (0);
}

int	horizontal(t_img *img, t_point from, t_point towards)
{
	int			j;
	t_segment	segment;

	segment.start = (int)from.x;
	segment.end = (int)towards.x;
	segment.st_col = from.color;
	segment.end_col = towards.color;
	j = (int)from.x;
	while (j < (int)towards.x)
	{
		if (within_bounds((int)j, (int)from.y))
			img_pix_put(img, (int)j, (int)from.y, color_this_pxl(j, segment));
		j++;
	}
	return (0);
}

int	naive_line(t_img *img, t_point from, t_point towards)
{
	int		j;
	double	i;
	double	dx;
	double	dy;
	t_line	line;

	dx = (towards.x - from.x);
	dy = (towards.y - from.y);
	if (towards.x < from.x)
		return (naive_line(img, towards, from));
	if (dx == 0)
		return (vertical(img, from, towards));
	if (dy == 0)
		return (horizontal(img, from, towards));
	j = (int)from.x;
	i = from.y;
	line.img = img;
	line.from = from;
	line.towards = towards;
	draw_it(line, i, j, dy / dx);
	return (0);
}
