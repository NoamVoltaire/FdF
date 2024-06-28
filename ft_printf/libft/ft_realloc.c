/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:24:19 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/11 17:30:43 by nvoltair         ###   ########.fr       */
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
