/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:34:40 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/19 19:39:38 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_convert2base(unsigned long long ull_save, int base,
				char *rtn, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			rtn[count - 1] = (ull_save % base) + 48;
		else
			rtn[count - 1] = (ull_save % base) + 55;
		ull_save /= base;
		count--;
	}
	return (rtn);
}

char	*ft_utoa_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_save;
	int					count;

	rtn = 0;
	count = 0;
	ull_save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	rtn = malloc(sizeof(char) * (count + 1));
	if (!rtn)
		return (NULL);
	rtn[count] = '\0';
	rtn = ft_convert2base(ull_save, base, rtn, count);
	return (rtn);
}
