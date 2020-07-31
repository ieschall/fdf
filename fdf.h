/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:55:27 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/30 23:55:05 by ieschall         ###   ########.fr       */
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

typedef struct	{
	float	x;
	float	y;
	float	z;
	t_u		color;
}			t_pnt;

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

#endif
