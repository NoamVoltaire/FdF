/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;

	i = 0;
	j = 0;
	dlen = ft_strlen(dst);
	while (dst[i] && i < size)
		i++;
	while (size && src[j] && i < size - 1)
		dst[i++] = src[j++];
	if (size && size >= dlen)
		dst[i] = 0;
	if (size < dlen)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + dlen);
}
