#include "fdf.h"

t_pnt	calc_center(t_pnt *p0, t_pnt *p1)
{
	return ((t_pnt){
		(p0->x + p1->x) / 2.f,
		(p0->y + p1->y) / 2.f,
		(p0->z + p1->z) / 2.f,
		0});
}

static void		apply_rotate(t_pnt **temp, t_u w, t_u h, t_var *var)
{
	int		i;
	int		j;
	t_pnt	center;

	i = 0;
	center = calc_center(&temp[0][0], &temp[h - 1][w - 1]);
	while (i != h)
	{
		j = 0;
		while (j != w)
		{
			if (var->angle_x || var->angle_y || var->angle_z)
			{
				temp[i][j] = move(temp[i][j], -center.x, -center.y, -center.z);
				temp[i][j] = rotate_x(temp[i][j], var->angle_x);
				temp[i][j] = rotate_y(temp[i][j], var->angle_y);
				temp[i][j] = rotate_z(temp[i][j], var->angle_z);
				temp[i][j] = move(temp[i][j], center.x, center.y, center.z);
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
				fdf->map_copy[i][j] = move(fdf->map_copy[i][j], fdf->var.move_x, fdf->var.move_y, 0);
			j += 1;
		}
		i += 1;
	}
	apply_rotate(fdf->map_copy, fdf->w, fdf->h, &fdf->var);
}
