/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:23:28 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/30 22:40:58 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt	**memory_allocate(t_u height, t_u width)
{
	t_pnt	**map;
	t_u		i;

	if (!(map = (t_pnt**)malloc(sizeof(t_pnt*) * (height + 1))))
		error(ERR_NO_MEMORY, NULL);
	map[height] = 0;
	i = 0;
	while (i < height)
	{
		if (!(map[i] = (t_pnt *)malloc(sizeof(t_pnt) * width)))
		{
			ft_memrelease((void**)map);
			error(ERR_NO_MEMORY, NULL);
		}
		i += 1;
	}
	return (map);
}
