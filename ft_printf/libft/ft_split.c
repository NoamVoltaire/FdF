/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:37:37 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/10 02:56:13 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] && s[i] != c)
				count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*wordcopy(char const *s, char c, int i)
{
	unsigned int	tmp_i;
	char			*word;

	tmp_i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		tmp_i++;
	}
	word = (char *)malloc((tmp_i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	else
	{
		i -= tmp_i;
		tmp_i = 0;
		while (s[i] && s[i] != c)
		{
			word[tmp_i] = s[i];
			i++;
			tmp_i++;
		}
		word[tmp_i] = 0;
	}
	return (word);
}

static int	fill_w_arr(char **arr, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i] && j < wordcount(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			arr[j] = wordcopy(s, c, i);
			if (!arr[j])
			{
				while (j > 0)
					free(arr[j--]);
				return (free(arr), 0);
			}
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	arr[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_w_arr(arr, s, c))
		return (NULL);
	return (arr);
}
