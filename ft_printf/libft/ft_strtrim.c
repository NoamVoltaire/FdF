/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 05:55:34 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/20 02:48:12 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	trimlength(char const *s1, char const *set)
{
	unsigned int	len;

	len = 0;
	while (*s1 && is_in_set(*s1, set))
		s1++;
	if (*s1)
		len = ft_strlen(s1) - 1;
	else
		return (0);
	while (s1[len] && is_in_set(s1[len], set) && len > 0)
		len--;
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	unsigned int	len;
	unsigned int	start;

	start = 0;
	len = 0;
	if (!(s1 && set))
		return (NULL);
	if (!*s1 || !*set)
	{
		trimmed = ft_strdup(s1);
		if (!trimmed)
			return (NULL);
	}
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	len = trimlength(s1, set);
	trimmed = (char *)malloc((len + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	trimmed[len] = 0;
	return (trimmed);
}
