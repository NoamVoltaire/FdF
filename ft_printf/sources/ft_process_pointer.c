/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_pointer(char *pointer, t_flags flags)
{
	int	char_count;

	char_count = 0;
	char_count += ft_precisionprint("0x", 2);
	if (flags.precision >= 0)
	{
		char_count += ft_process_width(flags.precision, ft_strlen(pointer), 1);
		char_count += ft_precisionprint(pointer, flags.precision);
	}
	else
		char_count += ft_precisionprint(pointer, ft_strlen(pointer));
	return (char_count);
}

int	ft_process_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ull == 0 && flags.precision == 0)
	{
		char_count += ft_precisionprint("0x", 2);
		return (char_count += ft_process_width(flags.width, 0, 1));
	}
	pointer = ft_ulltoa_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.precision < ft_strlen(pointer))
		flags.precision = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_print_pointer(pointer, flags);
	char_count += ft_process_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_print_pointer(pointer, flags);
	free(pointer);
	return (char_count);
}
