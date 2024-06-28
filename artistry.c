/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artistry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:42:01 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/02 12:47:41 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	line_exists(t_point from, t_point to)
{
	if (!within_bounds(from.x, from.y) \
		&& !within_bounds(to.x, to.y))
		return (0);
	return (1);
}

void	line2seg(t_line line, t_segment *segment)
{
	segment->start = (int)line.from.x;
	segment->end = (int)line.towards.x;
	segment->st_col = (int)line.from.color;
	segment->end_col = (int)line.towards.color;
}

int	corner_draw(t_fdf *fdf, int i, int j)
{
	t_point	here;
	t_point	y_neighbor;
	t_point	x_neighbor;

	here = space_2_iso_plan(*fdf, &fdf->mapdata, i, j);
	x_neighbor = space_2_iso_plan(*fdf, &fdf->mapdata, i, j + 1);
	y_neighbor = space_2_iso_plan(*fdf, &fdf->mapdata, i + 1, j);
	naive_line(&fdf->mlx.img, here, x_neighbor);
	naive_line(&fdf->mlx.img, here, y_neighbor);
	return (0);
}

int	corner_draw_two(t_fdf *fdf, int i, int j)
{
	t_point	here;
	t_point	x_neighbor;

	here = space_2_iso_plan(*fdf, &fdf->mapdata, i, j);
	x_neighbor = space_2_iso_plan(*fdf, &fdf->mapdata, i, j + 1);
	naive_line(&fdf->mlx.img, here, x_neighbor);
	return (0);
}

int	edge_draw(t_fdf *fdf, int i, int j)
{
	t_point	here;
	t_point	x_neighbor;

	here = space_2_iso_plan(*fdf, &fdf->mapdata, i, j);
	x_neighbor = space_2_iso_plan(*fdf, &fdf->mapdata, i + 1, j);
	naive_line(&fdf->mlx.img, here, x_neighbor);
	return (0);
}
