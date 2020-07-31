#include "fdf.h"

void	render_line(t_pnt p0, t_pnt p1, t_img *img)
{
	int		sign[2];
	int		error[2];
	int		delta[2];

	delta[0] = labs((int)p1.x - (int)p0.x);
	delta[1] = labs((int)p1.y - (int)p0.y);
	sign[0] = (int)p0.x < (int)p1.x ? 1 : (-1);
	sign[1] = (int)p0.y < (int)p1.y ? 1 : (-1);
	error[0] = delta[0] - delta[1];
	while ((int)p0.x != (int)p1.x || (int)p0.y != (int)p1.y)
	{
		if ((p0.x >= 0 && p0.x < img->w) && (p0.y >= 0 && p0.y < img->h))
			img->pixel_data[(int)p0.x + img->w * (int)p0.y] = p0.color;
		error[1] = error[0] * 2;
		if (error[1] > -(delta[1]))
		{
			error[0] -= (delta[1]);
			p0.x = (int)(p0.x) + sign[0];
		}
		if (error[1] < delta[0])
		{
			error[0] += (delta[0]);
			p0.y = (int)(p0.y) + sign[1];
		}
	}
}

void	render_map(t_pnt **map, t_u w, t_u h, t_img *img)
{
	t_u i;
	t_u j;

	i = 0;
	while (i != h)
	{
		j = 0;
		while (j != w)
		{
			if (j != (w - 1))
				render_line(map[i][j], map[i][j + 1], img);
			if (i != (h - 1))
				render_line(map[i][j], map[i + 1][j], img);
			j += 1;
		}
		i += 1;
	}
}
