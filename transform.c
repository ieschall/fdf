#include "render.h"

static t_pnt	calc_center(t_pnt *p0, t_pnt *p1)
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

void			apply_transform(t_pnt **map, t_u w, t_u h, t_pnt **temp, t_var *var)
{
	int		i;
	int		j;

	i = 0;
	while (i != h)
	{
		j = 0;
		while (j != w)
		{
			temp[i][j] = map[i][j];
			if (var->scale_xy || var->scale_z)
				temp[i][j] = scale(temp[i][j],
					var->scale_xy ? var->scale_xy : 1,
						var->scale_z ? var->scale_z : 1);
			if (var->move_x || var->move_y)
				temp[i][j] = move(temp[i][j], var->move_x, var->move_y, 0);
			j += 1;
		}
		i += 1;
	}
	apply_rotate(temp, w, h, var);
}
