/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:11:55 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/11 18:36:32 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_int(char *d_i, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if ((save_i < 0) && flags.precision >= 0)
		ft_putchar('-');
	if (flags.precision >= 0)
		char_count += ft_process_width(flags.precision - 1,
				ft_strlen(d_i) - 1, 1);
	char_count += ft_precisionprint(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_field_process_int(char *d_i, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_print_int(d_i, save_i, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(d_i))
		flags.precision = ft_strlen(d_i);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		char_count += ft_process_width(flags.width, 0, 0);
	}
	else
		char_count += ft_process_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_print_int(d_i, save_i, flags);
	return (char_count);
}

void	neg_case(int i, int char_count, t_flags flags)
{
	if ((i < 0) && (flags.precision >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.precision == -1)
			ft_precisionprint("-", 1);
		if (i != INT_MIN)
		{
			i *= -1;
			flags.width--;
			char_count++;
		}
	}
}

int	ft_process_int(int i, t_flags flags)
{
	char	*d_i;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	if (flags.precision == 0 && i == 0)
	{
		char_count += ft_process_width(flags.width, 0, 0);
		return (char_count);
	}
	neg_case(i, char_count, flags);
	if (i == INT_MIN && (flags.precision >= 0 || flags.zero == 1))
	{
		char_count ++;
		flags.width--;
		d_i = ft_strdup("2147483648");
	}
	else
		d_i = ft_itoa(i);
	char_count += ft_field_process_int(d_i, save_i, flags);
	free(d_i);
	return (char_count);
}
