/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_uint(char *unsi_int, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.precision >= 0)
		char_count += ft_process_width(flags.precision - 1,
				ft_strlen(unsi_int) - 1, 1);
	char_count += ft_precisionprint(unsi_int, ft_strlen(unsi_int));
	return (char_count);
}

static int	ft_field_process_uint(char *unsi_int, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_print_uint(unsi_int, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(unsi_int))
		flags.precision = ft_strlen(unsi_int);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		char_count += ft_process_width(flags.width, 0, 0);
	}
	else
		char_count += ft_process_width(flags.width,
				ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_print_uint(unsi_int, flags);
	return (char_count);
}

int	ft_process_uint(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;
	int		char_count;

	char_count = 0;
	if (flags.precision == 0 && unsi == 0)
	{
		char_count += ft_process_width(flags.width, 0, 0);
		return (char_count);
	}
	unsi_int = ft_utoa(unsi);
	char_count += ft_field_process_uint(unsi_int, flags);
	free(unsi_int);
	return (char_count);
}
