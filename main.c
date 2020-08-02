/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:55:00 by ieschall          #+#    #+#             */
/*   Updated: 2020/08/02 05:30:41 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*fdf_prepare(char **av)
{
	t_fdf	*fdf;

	if (!(fdf = ft_memalloc(sizeof(t_fdf))))
		error(ERR_NO_MEMORY, NULL);
	if (mlx_prepare(&fdf->mlx, 1366, 32, 0))
		return (NULL);
	fdf->h = get_height(open_file(av));
	fdf->w = get_width(open_file(av), av);
	fdf->map = memory_allocate(fdf->h, fdf->w);
	fdf->map_copy = memory_allocate(fdf->h, fdf->w);
	write_map(open_file(av), fdf->map);
	fdf->img.w = 1366;
	fdf->img.h = 768;
	fdf->img.pixel_data = fdf->mlx.plot;
	return (fdf);
}

void	prepare_map(t_fdf *fdf)
{
	t_pnt	center;

	ft_bzero(&fdf->var, sizeof(t_var));
	fdf->var.scale_xy = 0.5f / ((fdf->w > fdf->h ? fdf->w : fdf->h) / 1366.f);
	fdf->var.scale_z = 2;
	fdf->var.angle_x = 45 * M_PI / 180.f;
	fdf->var.angle_y = 35.264f * M_PI / 180.f;
	apply_transform(fdf);
	center = calc_center(&fdf->map_copy[0][0],
									&fdf->map_copy[fdf->h - 1][fdf->w - 1]);
	fdf->var.move_x = 1366 / 2 - center.x;
	fdf->var.move_y = 768 / 2 - center.y;
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		error(ERR_NO_PARAM, av);
	if (!(fdf = fdf_prepare(av)))
		return (-1);
	prepare_map(fdf);
	draw(fdf);
	completed(); // ВОЗМОЖНО УДАЛИТЬ
	// ВОПРОС В ДРУГОМ - ПОЧЕМУ ПРОГРАММА ЗАКАНЧИВАЕТ РАБОТУ ДО return (0)?
	// ИЗ-ЗА ТОГО, ЧТО В ОКНЕ Я НАЖИМАЮ ESC?
	mlx_hook(fdf->mlx.win, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx.ptr);
	return (0);
}
