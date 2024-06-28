/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:30:09 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/04 00:03:45 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

int	gradient(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	color_this_pxl(int current, t_segment segment)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (segment.st_col == segment.end_col)
		return (segment.st_col);
	percentage = percent(segment.start, segment.end, current);
	red = gradient((segment.st_col >> 16) & 0xFF, \
		(segment.end_col >> 16) & 0xFF, percentage);
	green = gradient((segment.st_col >> 8) & 0xFF, \
		(segment.end_col >> 8) & 0xFF, percentage);
	blue = gradient(segment.st_col & 0xFF, segment.end_col & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	z_dependant_color(t_mapdata *mapdata, int z)
{
	double	percentz;
	int		r;
	int		g;
	int		b;

	if (mapdata->peak == mapdata->valley)
		return (WHITE);
	if (z >= 0)
	{
		percentz = percent(0, mapdata->peak, z);
		r = gradient((YELLOW >> 16) & 0xFF, (RED >> 16) & 0xFF, percentz);
		g = gradient((YELLOW >> 8) & 0xFF, (RED >> 8) & 0xFF, percentz);
		b = gradient(YELLOW & 0xFF, RED & 0xFF, percentz);
	}
	else
	{
		percentz = percent(0, mapdata->valley, z);
		r = gradient((GREEN >> 16) & 0xFF, (BLUE >> 16) & 0xFF, percentz);
		g = gradient((GREEN >> 8) & 0xFF, (BLUE >> 8) & 0xFF, percentz);
		b = gradient(GREEN & 0xFF, BLUE & 0xFF, percentz);
	}
	return ((r << 16) | (g << 8) | b);
}
