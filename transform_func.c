/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:35:08 by ieschall          #+#    #+#             */
/*   Updated: 2020/08/01 20:40:46 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt	rotate_x(t_pnt p, float radian)
{
	return ((t_pnt){
		p.x,
		p.y * cos(radian) - p.z * sin(radian),
		p.y * sin(radian) + p.z * cos(radian),
		p.color});
}

t_pnt	rotate_y(t_pnt p, float radian)
{
	return ((t_pnt){
		p.x * cos(radian) - p.z * sin(radian),
		p.y,
		p.x * sin(radian) + p.z * cos(radian),
		p.color});
}

t_pnt	rotate_z(t_pnt p, float radian)
{
	return ((t_pnt){
		p.x * cos(radian) - p.y * sin(radian),
		p.x * sin(radian) + p.y * cos(radian),
		p.z,
		p.color});
}

t_pnt	move(t_pnt p, float x, float y, float z)
{
	return ((t_pnt){
		p.x + x,
		p.y + y,
		p.z + z,
		p.color});
}

t_pnt	scale(t_pnt p, float alpha, float beta)
{
	return ((t_pnt){
		p.x * alpha,
		p.y * alpha,
		p.z * beta,
		p.color});
}
