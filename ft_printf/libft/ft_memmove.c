/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:30:09 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/16 01:26:21 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (!(dst || src))
		return (0);
	if (a > b)
	{
		while (i < len)
		{
			*(a + len - 1) = *(b + len - 1);
			len--;
		}
	}
	else
	{
		while (i++ < len)
			a[i] = b[i];
	}
	return (dst);
}
