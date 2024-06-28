/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:44:55 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/06 07:59:12 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	check_filename(char *str)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (i <= 0)
		return (0);
	if (ft_strncmp((str + i), ".fdf", 4) == 0)
		return (1);
	else
		return (0);
}

int	fill_map(t_mapdata *mapdata, char *line, int k)
{
	int		i;
	char	**split_line;

	i = 0;
	split_line = ft_split(line, ' ');
	if (!split_line)
		return (ft_printf(SPLIT_FAIL_MSG), 0);
	while (split_line[i])
	{
		if (mapdata->has_color)
			color_case(mapdata, split_line[i], k, i);
		else
			mapdata->map[k][i] = ft_atoi(split_line[i]);
		if (mapdata->peak < mapdata->map[k][i])
			mapdata->peak = mapdata->map[k][i];
		if (mapdata->valley > mapdata->map[k][i])
			mapdata->valley = mapdata->map[k][i];
		free(split_line[i]);
		i++;
	}
	free(split_line);
	return (1);
}

int	fill_it(int fdfile, t_mapdata *mapdata)
{
	int		k;
	char	*read_line;

	k = 0;
	read_line = get_next_line(fdfile);
	while (read_line)
	{
		if (k >= mapdata->height || !fill_map(mapdata, read_line, k))
		{	
			free(read_line);
			return (ft_printf("Unexpected error\n"), 0);
		}
		k++;
		free(read_line);
		read_line = get_next_line(fdfile);
	}
	free(read_line);
	close(fdfile);
	return (1);
}

int	mapcheck_2(int fdfile, t_mapdata *mapdata)
{
	mapdata->map = map_alloc(mapdata->height, mapdata->width);
	if (mapdata->has_color)
	mapdata->colors = map_alloc(mapdata->height, mapdata->width);
	if (!mapdata->map || (mapdata->has_color && !mapdata->colors))
		return (ft_printf("malloc error ??\n"), 1);
	if (!fill_it(fdfile, mapdata))
	{
		free_map(mapdata->map, mapdata->height);
		return (ft_printf("error while processing map\n"), 1);
	}
	return (ft_printf ("done\n"), 0);
}

int	mapcheck(int ac, char **av, t_mapdata *mapdata)
{
	int			fdfile;

	if (ac != 2)
		return (ft_printf("FdF :Invalid number of arguments.\n%s", \
		USAGE_MSG), 1);
	if (!check_filename(av[1]))
		return (ft_printf("%s", USAGE_MSG), 1);
	fdfile = open(av[1], O_RDONLY);
	if (fdfile < 1)
		return (ft_printf("failed to open file\n"), 1);
	if (!map_dim(fdfile, mapdata))
		return (ft_printf("couldn't read map\n"), 1);
	if (!mapdata->width)
		return (ft_printf("empty map\n"), 1);
	fdfile = open(av[1], O_RDONLY);
	if (fdfile < 0)
		return (ft_printf("%s :couldn't open file\n", av[1]), 1);
	return (mapcheck_2(fdfile, mapdata));
}
