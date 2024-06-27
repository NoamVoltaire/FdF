/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trgbtoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match_in_base(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_trgbtoi(const char *str)
{
	const char		*hexbase = "0123456789abcdef";
	unsigned int	res;

	res = 0;
	if (ft_strncmp(str, "0x", 2) != 0)
		return (0);
	str += 2;
	while (*str)
	{
		if (match_in_base(hexbase, ft_tolower(*str)) < 0)
			return (0);
		res = res * 16 + match_in_base(hexbase, ft_tolower(*str));
		str++;
	}
	return (res);
}
