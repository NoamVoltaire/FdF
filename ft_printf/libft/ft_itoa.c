/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlength(long long int num)
{
	int	len;

	len = 1;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	long long int	num;

	num = n;
	len = numlength(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = 0;
	len--;
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 9)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	str[len] = num % 10 + '0';
	return (str);
}
