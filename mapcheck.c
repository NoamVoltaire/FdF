/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	**map_alloc(int height, int width)
{
	int	**map;
	int	i;

	map = malloc((height) * sizeof(int *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = malloc((width) * sizeof(int));
		if (!(map + i))
		{
			free_map(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}

char	***colors_alloc(int height, int width)
{
	char	***str;
	int		i;

	str = malloc((height + 1) * sizeof(char **));
	if (!str)
		return (NULL);
	str[height] = NULL;
	i = 0;
	while (i < height)
	{
		str[i] = malloc((width + 1) * sizeof(char *));
		if (!(str + i))
		{
			while (i-- >= 0)
				free_str(str[i]);
			return (NULL);
		}
		str[i][width] = NULL;
		i++;
	}
	return (str);
}

int	right_format(char c)
{
	if (ft_isdigit(c) || is_hexcode(c) || c == ' ' || c == ',' || c == '-')
		return (1);
	else
		return (0);
}

int	checkline(char *str, t_mapdata *mapdata)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!right_format(str[i]))
			return (0);
		if (!mapdata->has_color && str[i] == ',')
		{	
			if (is_color_coded(str + i + 1))
				mapdata->has_color = 1;
			else
				return (1);
		}
		i++;
	}
	return (1);
}

int	map_dim(int fd, t_mapdata *mapdata)
{
	int		status;
	int		height;
	int		width;
	char	*line;

	height = 0;
	width = 1;
	status = 1;
	line = get_next_line(fd);
	if (checkline(line, mapdata))
		mapdata->width = wordcount(line, ' ');
	while (line && status > 0 && width > 0)
	{	
		status = checkline(line, mapdata);
		width = wordcount(line, ' ');
		if (width != mapdata->width)
			status = 0;
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	mapdata->height = height;
	return (status);
}
