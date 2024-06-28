/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:34:02 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/01 22:15:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.precision = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.sharp = 0;
	return (flags);
}

void	non_breaking_flags(const char *save, int i,
		t_flags *flags, va_list args)
{
	if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
		flags->zero = 1;
	if (save[i] == '.')
	{
		i = ft_flag_dot(save, i, flags, args);
		flags->zero = 0;
	}
	if (save[i] == '-')
		*flags = ft_flag_minus(*flags);
	if (save[i] == '#')
		flags->sharp = 1;
	if (save[i] == '*')
		*flags = ft_flag_width(args, *flags);
	if (ft_isdigit(save[i]))
		*flags = ft_flag_digit(save[i], *flags);
}

int	ft_process_flags(const char *save, int i,
		t_flags *flags, va_list args)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_isconverter(save[i])
			&& !ft_isflag(save[i]))
			break ;
		non_breaking_flags(save, i, flags, args);
		if (ft_isconverter(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	compute_str(const char *save, va_list args)
{
	int		i;
	t_flags	flags;
	int		char_count;

	i = 0;
	char_count = 0;
	flags = ft_init_flags();
	while (save[i])
	{
		flags = ft_init_flags();
		if (save[i] == '%' && save[i + 1])
		{
			i = ft_process_flags(save, ++i, &flags, args);
			if (ft_isconverter(save[i]))
				char_count += ft_conversion((char)flags.type, flags, args);
			else if (save[i])
				char_count += write(1, save + i, 1);
		}
		else
			char_count += write(1, save + i, 1);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		char_count;

	char_count = 0;
	va_start(args, input);
	char_count += compute_str(input, args);
	va_end(args);
	return (char_count);
}
