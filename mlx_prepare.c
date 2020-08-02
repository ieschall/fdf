/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_prepare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:35:00 by ieschall          #+#    #+#             */
/*   Updated: 2020/08/02 04:32:21 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_prepare(t_mlx *mlx, int line, int color, int endian)
{
	if (!(mlx->ptr = mlx_init()))
		return (-1);
	if (!(mlx->win = mlx_new_window(mlx->ptr, 1366, 768, "FDF")))
	{
		free(mlx->ptr);
		return (-1);
	}
	if (!(mlx->img_plot = mlx_new_image(mlx->ptr, 1366, 768)))
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		return (-1);
	}
	if (!(mlx->plot = mlx_get_data_addr(mlx->img_plot, &color, &line, &endian)))
	{
		mlx_destroy_image(mlx->ptr, mlx->win);
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		return (-1);
	}
	return (0);
}
