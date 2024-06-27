/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:45:54 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/1 23:07:23 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	ft_memset(&fdf, 0, sizeof(t_fdf));
	if (ac != 2)
		return (ft_printf("%s\n", USAGE_MSG), 1);
	if (mapcheck(ac, av, &fdf.mapdata))
		return (1);
	setup_default(&fdf);
	if (pop_the_window(&fdf))
	{
		free_maps(&fdf.mapdata);
		return (ft_printf("mlx error"), 1);
	}
	free_maps(&fdf.mapdata);
	return (0);
}
