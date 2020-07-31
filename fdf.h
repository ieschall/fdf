/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:55:27 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/31 22:57:12 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define SPACE					(' ')
# define TAB					('\t')

# define ERR_NO_PARAM			(-1)
# define ERR_NO_FILE			(-2)
# define ERR_FILE_NO_VALID		(-3)
# define ERR_NO_MEMORY			(-4)
# define ERR					(-5)

# define LOWERCASE				(1)
# define UPPERCASE				(2)

typedef unsigned t_u;

typedef struct	s_mlx{
	void		*ptr;
	void		*win;
	void		*img_plot;
	void		*plot;
}				t_mlx;

typedef struct	{
	float	x;
	float	y;
	float	z;
	t_u		color;
}			t_pnt;

typedef struct	{
	t_u		w;
	t_u		h;
	t_u		*pixel_data;
}			t_img;

typedef struct	{
	float	move_x;
	float	move_y;

	float	angle_x;
	float	angle_y;
	float	angle_z;

	float	scale_z;
	float	scale_xy;
}			t_var;

typedef struct {
	t_mlx	mlx;
	t_img	img;
	t_pnt	**map;
	t_pnt	**map_copy;
	t_var	var;
	t_u		w;
	t_u		h;
}			t_fdf;

void		error(int code, char **av);
void		error_gnl(int result_gnl, char *line, t_pnt **map);
void		error_split(char *line, t_pnt **map);
void		error_file_no_valid(char **arr_split, t_pnt **map);

int			is_digit(int с);
int			is_sign(int с);
int			is_alphabet(int с);
int			is_x(int c);
int			is_comma(int c);

int			open_file(char **av);
t_pnt		**memory_allocate(t_u height, t_u width);

t_u			get_height(int fd);
t_u			get_width(int fd, char **av);
t_u			get_digit_count(char *line);
t_u			check_rect(char *line, char **av, t_u digit_count, t_u width);

void		write_map(int fd, t_pnt **map);
void		check_values(char **split, t_pnt **map, t_u height, t_u width);
t_u			check_hexad(t_u i, t_u j, char **split, t_pnt **map);
void		write_values(t_u height, t_u width, char *split, t_pnt **map);

void		render_line(t_pnt p0, t_pnt p1, t_img *img);
void		render_map(t_pnt **map, t_u w, t_u h, t_img *img);
void		apply_transform(t_fdf *fdf);
t_pnt		rotate_x(t_pnt p, float radian);
t_pnt		rotate_y(t_pnt p, float radian);
t_pnt		rotate_z(t_pnt p, float radian);
t_pnt		move(t_pnt p, float x, float y, float z);
t_pnt		scale(t_pnt p, float alpha, float beta);
int			mlx_prepare(t_mlx *mlx, int line, int color, int endian);
int			key_press(int keycode, void *p);
void		draw(t_fdf *f);
t_pnt		calc_center(t_pnt *p0, t_pnt *p1);
void		prepare_map(t_fdf *fdf);

#endif
