/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:35:06 by ieschall          #+#    #+#             */
/*   Updated: 2020/08/01 21:17:42 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt			calc_center(t_pnt *p0, t_pnt *p1)
{
	return ((t_pnt){
		(p0->x + p1->x) / 2.f,
		(p0->y + p1->y) / 2.f,
		(p0->z + p1->z) / 2.f,
		0});
}

static void		apply_rotate(t_pnt **map_copy, t_u w, t_u h, t_var *var)
{
	int		i;
	int		j;
	t_pnt	center;

	i = 0;
	center = calc_center(&map_copy[0][0], &map_copy[h - 1][w - 1]);
	while (i != h)
	{
		j = 0;
		while (j != w)
		{
			if (var->angle_x || var->angle_y || var->angle_z)
			{
				map_copy[i][j] = move(map_copy[i][j], -center.x, -center.y,
																	-center.z);
				map_copy[i][j] = rotate_x(map_copy[i][j], var->angle_x);
				map_copy[i][j] = rotate_y(map_copy[i][j], var->angle_y);
				map_copy[i][j] = rotate_z(map_copy[i][j], var->angle_z);
				map_copy[i][j] = move(map_copy[i][j], center.x, center.y,
																	center.z);
			}
			j += 1;
		}
		i += 1;
	}
}

void			apply_transform(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i != fdf->h)
	{
		j = 0;
		while (j != fdf->w)
		{
			fdf->map_copy[i][j] = fdf->map[i][j];
			if (fdf->var.scale_xy || fdf->var.scale_z)
				fdf->map_copy[i][j] = scale(fdf->map_copy[i][j],
					fdf->var.scale_xy ? fdf->var.scale_xy : 1,
						fdf->var.scale_z ? fdf->var.scale_z : 1);
			if (fdf->var.move_x || fdf->var.move_y)
				fdf->map_copy[i][j] = move(fdf->map_copy[i][j],
										fdf->var.move_x, fdf->var.move_y, 0);
			j += 1;
		}
		i += 1;
	}
	apply_rotate(fdf->map_copy, fdf->w, fdf->h, &fdf->var);
}
