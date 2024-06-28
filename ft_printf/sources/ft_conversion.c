/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:00:49 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/10 17:02:54 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isconverter(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '#') || (c == '+') || (c == '-')
		|| (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int	ft_isnum_converter(char c)
{
	return ((c == 'd') || (c == 'i') || (c == 'u') || (c == 'x') || (c == 'X'));
}

int	ft_conversion(int c, t_flags flags, va_list args)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_process_char(va_arg(args, int), flags);
	else if (c == 's')
		char_count = ft_process_string(va_arg(args, char *), flags);
	else if (c == 'p')
		char_count = ft_process_pointer(va_arg(args,
					unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = ft_process_int(va_arg(args, int), flags);
	else if (c == 'u')
		char_count += ft_process_uint((unsigned int)va_arg(args,
					unsigned int), flags);
	else if (c == 'x')
		char_count += ft_process_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += ft_process_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		char_count += ft_process_percent(flags);
	return (char_count);
}
