/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int				sharp;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				precision;
	int				star;
	int				plus;
	int				space;
}					t_flags;

int					abs_val(int n);
int					ft_printf(const char *format, ...);
int					ft_isconverter(int c);
int					ft_isflag(int c);
int					ft_conversion(int c, t_flags flags, va_list args);
int					ft_process_width(int width, int minus, int has_zero);
int					ft_precisionprint(char *str, int prec);
int					ft_process_char(char c, t_flags flags);
int					ft_process_string(char *str, t_flags flags);
int					ft_process_int(int i, t_flags flags);
int					ft_process_percent(t_flags flags);
int					ft_process_hex(unsigned int ui, int lower, t_flags flags);
int					ft_process_uint(unsigned int unsi, t_flags flags);
int					ft_flag_dot(const char *save, int start,
						t_flags *flags, va_list args);
int					ft_putchar(int c);
int					ft_process_pointer(unsigned long long pointer,
						t_flags flags);

char				*ft_ulltoa_base(unsigned long long ull, int base);
char				*ft_utoa(unsigned int n);
char				*ft_str_tolower(char *str);

t_flags				ft_flag_star(t_flags flags);
t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_width(va_list args, t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);
#endif