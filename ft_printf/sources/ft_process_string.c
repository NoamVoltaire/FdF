/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:10:03 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/18 14:31:05 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_string(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.precision >= 0)
	{
		char_count += ft_process_width(flags.precision, ft_strlen(str), 0);
		char_count += ft_precisionprint(str, flags.precision);
	}
	else
	{
		char_count += ft_precisionprint(str, ft_strlen(str));
	}
	return (char_count);
}

int	ft_process_string(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_print_string(str, flags);
	if (flags.precision >= 0)
		char_count += ft_process_width(flags.width, flags.precision, 0);
	else
		char_count += ft_process_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_print_string(str, flags);
	return (char_count);
}
