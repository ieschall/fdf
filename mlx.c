#include "fdf.h"

static void	key_press2(int keycode, void *p)
{
	if (keycode == 123)
		((t_fdf*)p)->var.move_x -= 5;
	else if (keycode == 124)
		((t_fdf*)p)->var.move_x += 5;
	else if (keycode == 126)
		((t_fdf*)p)->var.move_y -= 5;
	else if (keycode == 125)
		((t_fdf*)p)->var.move_y += 5;
	else if (keycode == 91)
		((t_fdf*)p)->var.angle_x += 0.0174533f;
	else if (keycode == 84)
		((t_fdf*)p)->var.angle_x -= 0.0174533f;
	else if (keycode == 88)
		((t_fdf*)p)->var.angle_y -= 0.0174533f;
	else if (keycode == 86)
		((t_fdf*)p)->var.angle_y += 0.0174533f;
	else if (keycode == 92)
		((t_fdf*)p)->var.angle_z += 0.0174533f;
	else if (keycode == 89)
		((t_fdf*)p)->var.angle_z -= 0.0174533f;
}

void		draw(t_fdf *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	ft_bzero(f->img.pixel_data, f->img.w * f->img.h * 4);
	apply_transform(f);
	render_map(f->map_copy, f->w, f->h, &f->img);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img_plot, 0, 0);
}

int			key_press(int keycode, void *p)
{
	if (keycode == 53)
		exit (0);
	else if (keycode == 116)
		((t_fdf*)p)->var.scale_z += 1;
	else if (keycode == 121)
		((t_fdf*)p)->var.scale_z -= 1;
	else if (keycode == 69 || keycode == 78)
		((t_fdf*)p)->var.scale_xy += keycode == 69 ? 1 : -1;
	else if (keycode == 36)
		prepare_map(p);
	else
		key_press2(keycode, p);
	draw(p);
	return (0);
}