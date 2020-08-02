/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:34:53 by ieschall          #+#    #+#             */
/*   Updated: 2020/08/02 05:11:58 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ESC (53)
#define ENTER (36)

#define LEFT_ARROW	(123)
#define RIGHT_ARROW	(124)
#define UP_ARROW	(126)
#define DOWN_ARROW	(125)

#define W (13)
#define S (1)
#define D (2)
#define A (0)
#define Q (12)
#define E (14)

#define PLUS	(24)
#define MINUS	(27)

#define ARROW_LEFT	(43)
#define ARROW_RIGHT	(47)

static void	key_press_variation(int keycode, void *p)
{
	if (keycode == LEFT_ARROW)
		((t_fdf*)p)->var.move_x -= 5;
	else if (keycode == RIGHT_ARROW)
		((t_fdf*)p)->var.move_x += 5;
	else if (keycode == UP_ARROW)
		((t_fdf*)p)->var.move_y -= 5;
	else if (keycode == DOWN_ARROW)
		((t_fdf*)p)->var.move_y += 5;
	else if (keycode == W)
		((t_fdf*)p)->var.angle_x += 0.0174533f;
	else if (keycode == S)
		((t_fdf*)p)->var.angle_x -= 0.0174533f;
	else if (keycode == D)
		((t_fdf*)p)->var.angle_y -= 0.0174533f;
	else if (keycode == A)
		((t_fdf*)p)->var.angle_y += 0.0174533f;
	else if (keycode == Q)
		((t_fdf*)p)->var.angle_z += 0.0174533f;
	else if (keycode == E)
		((t_fdf*)p)->var.angle_z -= 0.0174533f;
}

static void	menu_advanced(t_fdf *f)
{
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 90, 0xC600, "Arrows:");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 90, 0xFF00FF,
	"                UP");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 110, 0xFF00FF,
	"          LEFT DOWN RIGHT");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 140, 0xC600, "Keyboard:");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 140, 0x404040,
	"          1 2 3 4 5 6 7 8 9 0");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 140, 0xFF99FF,
	"                              - +");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 160, 0x404040,
	"                 R T Y U I O P");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 160, 0xFF99FF,
	"           Q   E");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 160, 0xFF00FF,
	"             W");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 180, 0x404040,
	"                  F G H J K L");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 180, 0xFF00FF,
	"            A S D");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 200, 0x404040,
	"             Z X C V B N M");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 200, 0xFF99FF,
	"                           < >");
}

static void	menu(t_fdf *f)
{
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 5, 0xC600,
	"Friend, the following keyboard keys are available to you:");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 40, 0xC600, "Exit:");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 40, 0xFF00FF, "       ESC");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 60, 0xC600, "Reset:");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 60, 0xFF00FF, "       ENTER");
	menu_advanced(f);
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 720, 0x004D1A,
	"by          and          aka");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 720, 0xCC06,
	"   ieschall     jbelinda     Holy");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 740, 0x004D1A,
	"at support");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 740, 0xCC06,
	"           vneelix");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 740, 0x004D1A,
	"                   he's best developer graphics branch in School 21");
}

void		draw(t_fdf *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	ft_bzero(f->img.pixel_data, f->img.w * f->img.h * 4);
	apply_transform(f);
	render_map(f->map_copy, f->w, f->h, &f->img);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img_plot, 0, 0);
	menu(f);
}

int			key_press(int keycode, void *p)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == ARROW_RIGHT)
		((t_fdf*)p)->var.scale_z += 1;
	else if (keycode == ARROW_LEFT)
		((t_fdf*)p)->var.scale_z -= 1;
	else if (keycode == PLUS || keycode == MINUS)
		((t_fdf*)p)->var.scale_xy += keycode == PLUS ? 1 : -1;
	else if (keycode == ENTER)
		prepare_map(p);
	else
		key_press_variation(keycode, p);
	draw(p);
	return (0);
}
