/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 04:25:11 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/02 17:20:44 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapped;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	mapped = ft_strdup(s);
	if (!mapped)
		return (NULL);
	while (mapped[i])
	{
		mapped[i] = f(i, mapped[i]);
		i++;
	}
	mapped[i] = 0;
	return (mapped);
}
