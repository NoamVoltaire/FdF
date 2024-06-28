/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:17:14 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/27 08:14:41 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	free_map(int **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// void	free_colors(char ***str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free_str(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

void	free_maps(t_mapdata *mapdata)
{
	free_map(mapdata->map, mapdata->height);
	if (mapdata->colors)
		free_map(mapdata->colors, mapdata->height);
}
