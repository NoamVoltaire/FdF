/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_hexa(unsigned int ui, char *hexa, int lower, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.precision >= 0)
		char_count += ft_process_width(flags.precision - 1,
				ft_strlen(hexa) - 1, 1);
	if (ui != 0)
	{
		if (flags.sharp && lower)
			char_count += ft_precisionprint("0x", 2);
		if (flags.sharp && !lower)
			char_count += ft_precisionprint("0X", 2);
	}
	char_count += ft_precisionprint(hexa, ft_strlen(hexa));
	return (char_count);
}

static int	ft_field_process_hexa(unsigned int ui, char *hexa,
				int lower, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_print_hexa(ui, hexa, lower, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(hexa))
		flags.precision = ft_strlen(hexa);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		char_count += ft_process_width(flags.width, 0, 0);
	}
	else
		char_count += ft_process_width(flags.width,
				ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += ft_print_hexa(ui, hexa, lower, flags);
	return (char_count);
}

int	ft_process_hex(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		char_count;

	char_count = 0;
	if (flags.precision == 0 && ui == 0)
	{
		char_count += ft_process_width(flags.width, 0, 0);
		return (char_count);
	}
	hexa = ft_ulltoa_base((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	char_count += ft_field_process_hexa(ui, hexa, lower, flags);
	free(hexa);
	return (char_count);
}
