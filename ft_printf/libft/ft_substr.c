/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:57:20 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/19 15:16:35 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	else
	{
		while (s[start + i] && i < len)
			i++;
	}
	sub = (char *)malloc((i + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	sub[i] = 0;
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
