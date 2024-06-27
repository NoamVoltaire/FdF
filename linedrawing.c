/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedrawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:45:54 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/1 23:07:23 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	negativ_slope(t_line line, t_segment segment, double i, int j)
{
	double	slope;
	int		cps;

	slope = (line.towards.y - line.from.y) / (line.towards.x - line.from.x);
	cps = 1;
	while ((i + (slope / 2) <= (i - cps)) && i - cps >= line.towards.y)
	{
		skip_some(line, i, j);
		if (within_bounds(j, (int)i - cps))
			img_pix_put(line.img, j, (int)i - cps, \
				color_this_pxl(j, segment));
		else
			break ;
		cps++;
	}
	while ((i + slope <= (i - cps)) && i - cps >= line.towards.y)
	{
		skip_some(line, i, j);
		if (within_bounds(j + 1, (int)i - cps))
			img_pix_put(line.img, j + 1, (int)i - cps, \
				color_this_pxl(j + 1, segment));
		else
			break ;
		cps++;
	}
}

void	positiv_slope(t_line line, t_segment segment, double i, int j)
{
	double	slope;
	int		cps;

	slope = (line.towards.y - line.from.y) / (line.towards.x - line.from.x);
	cps = 1;
	while ((i + (slope / 2) >= (i + cps)) && i + cps <= line.towards.y)
	{
		skip_some(line, i, j);
		if (within_bounds(j, (int)i + cps))
			img_pix_put(line.img, j, (int)i + cps, \
				color_this_pxl(j, segment));
		else
			break ;
		printf("i'm here\n");
		cps++;
	}
	while ((i + slope >= (i + cps)) && i + cps <= line.towards.y)
	{
		skip_some(line, i, j);
		if (within_bounds(j + 1, (int)i + cps) && i - cps < line.towards.y)
			img_pix_put(line.img, j + 1, (int)i + cps, \
				color_this_pxl(j + 1, segment));
		else
			break ;
		cps++;
	}
}

void	skip_some(t_line line, double i, int j)
{
	double	slope;

	slope = (line.towards.y - line.from.y) / (line.towards.x - line.from.x);
	while (i < 0 || j < 0 || i > WINDOW_HEIGHT || j > WINDOW_WIDTH)
	{
		if ((int)i == (int)line.towards.y || j == (int)line.towards.x)
			break ;
		i += slope;
		j++;
	}
}

void	skip_some_mor(t_line line, double i, int j)
{
	double	slope;

	slope = (line.towards.y - line.from.y) / (line.towards.x - line.from.x);
	while (i < 0 || i > WINDOW_HEIGHT)
	{
		if ((int)i == (int)line.towards.y && j == (int)line.towards.x)
		{
			printf("i'm here\n");
			break ;
		}
		i += slope;
		j++;
	}
}

void	what2do(t_line line, double i, int j, double slope)
{
	t_segment	segment;

	line2seg(line, &segment);
	if (slope < 0)
		negativ_slope(line, segment, i, j);
	positiv_slope(line, segment, i, j);
}

void	draw_it(t_line line, double i, int j, double slope)
{
	t_segment	segment;

	line2seg(line, &segment);
	skip_some(line, i, j);
	while (i >= 0 && (int)i < WINDOW_HEIGHT)
	{	
		skip_some_mor(line, i, j);
		if (j < (int)line.towards.x && \
			j < WINDOW_WIDTH && (int)i != (int)line.towards.y)
		{
			what2do(line, i, j, slope);
			if (within_bounds(j, (int)i))
				img_pix_put(line.img, j, (int)i, color_this_pxl(j, segment));
			else
				break ;
			j++;
		}
		else
			return ;
		i += slope;
	}
}
