/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 07:24:09 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/14 07:04:22 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_process_percent(t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_precisionprint("%", 1);
	char_count += ft_process_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
	char_count += ft_precisionprint("%", 1);
	return (char_count);
}
