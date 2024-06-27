/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/27 14:59:16 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t newsize)
{
	void	*new;
	size_t	oldsize;

	if (!old)
		return (malloc(newsize));
	oldsize = sizeof(old);
	if (oldsize >= newsize)
		return (old);
	new = malloc(newsize);
	ft_memcpy(new, old, oldsize);
	return (new);
}
