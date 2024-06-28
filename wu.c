/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:53:39 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/07 16:59:50 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <math.h>

int	min_of_2(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	swap(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

double	abs_valu(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

double	fpart(double val)
{
	if (val > 0)
		return (val - (int)val);
	return (val - (int)val - 1);
}

int	within_bounds(int x, int y)
{
	if (x < 0 || y < 0 || x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return (0);
	else
		return (1);
}
