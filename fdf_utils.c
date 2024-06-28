/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:41:53 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/21 04:53:01 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

size_t	wordcount(char const *s, char c)
{
	size_t			count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	is_color_coded(char *str)
{
	if (ft_strncmp(str, "0x", 2) == 0)
		return (1);
	else
		return (0);
}

int	is_hexcode(char c)
{
	if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || c == 'x')
		return (1);
	else
		return (0);
}

void	color_case(t_mapdata *mapdata, char *line, int k, int i)
{
	char	**val_n_col;

	val_n_col = ft_split(line, ',');
	mapdata->map[k][i] = ft_atoi(val_n_col[0]);
	if (val_n_col[1])
		mapdata->colors[k][i] = ft_trgbtoi(val_n_col[1]);
	else
		mapdata->colors[k][i] = WHITE;
	free_str(val_n_col);
}
