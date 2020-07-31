/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:55:00 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/30 22:40:35 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_pnt	**map;
	t_u		height;
	t_u		width;

	if (ac != 2)
		error(ERR_NO_PARAM, av);
	height = get_height(open_file(av));
	width = get_width(open_file(av), av);
	// УДАЛИТЬ
	printf("\nheight  = %f\nlwidth = %f\n\n", height, width);
	// УДАЛИТЬ
	map = memory_allocate(height, width);
	write_map(open_file(av), map);
	ft_memrelease((void**)map);
	return (0);
}
