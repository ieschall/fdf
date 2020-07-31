/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 23:00:40 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/31 00:13:10 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include <stdlib.h>

typedef unsigned t_u;

typedef struct	{
	t_u		w;
	t_u		h;
	t_u		*pixel_data;
}			t_img;

typedef struct	{
	float	x;
	float	y;
	float	z;
	t_u		color;
}			t_pnt;

typedef struct	{
	float	move_x;
	float	move_y;

	float	angle_x;
	float	angle_y;
	float	angle_z;

	float	scale_z;
	float	scale_xy;
}			t_var;

void		render_line(t_pnt p0, t_pnt p1, t_img *img);
void		render_map(t_pnt **map, t_u w, t_u h, t_img *img);

void		apply_transform(t_pnt **map, t_u w, t_u h, t_pnt **map_copy, t_var *var);

t_pnt		rotate_x(t_pnt p, float radian);
t_pnt		rotate_y(t_pnt p, float radian);
t_pnt		rotate_z(t_pnt p, float radian);
t_pnt		move(t_pnt p, float x, float y, float z);
t_pnt		scale(t_pnt p, float alpha, float beta);

#endif
