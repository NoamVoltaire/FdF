/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapclean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:33:51 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/16 15:10:44 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	compute_offsets(t_fdf *fdf)
{
	t_point	center;

	fdf->x_offset = 0;
	fdf->y_offset = 0;
	center = space_2_iso_plan(*fdf, &fdf->mapdata, \
		fdf->mapdata.height / 2, fdf->mapdata.width / 2);
	fdf->x_offset = -((int)center.x - WINDOW_WIDTH / 2);
	fdf->y_offset = -((int)center.y - WINDOW_HEIGHT / 2);
}

void	setup_default(t_fdf *fdf)
{
	int	zoom;

	zoom = min_of_2(WINDOW_WIDTH / (1.30 * fdf->mapdata.width), \
		WINDOW_HEIGHT / (1.30 * fdf->mapdata.height));
	fdf->to_scale = 0;
	fdf->zoom = zoom;
	fdf->h_dist = HEIGHT_DIST;
	compute_offsets(fdf);
	fdf->angles.x = 0;
	fdf->angles.y = 0;
	fdf->angles.z = 0;
}
