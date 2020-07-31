/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:15:28 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/30 22:44:31 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		write_values(t_u height, t_u width, char *split, t_pnt **map)
{
	t_u shift;
	t_u i;

	map[height][width].x = height;
	map[height][width].y = width;
	map[height][width].z = ft_atoi(split);
	i = 0;
	while (split[i] && !is_comma(split[i]))
		i += 1;
	map[height][width].color = is_comma(split[i]) ? 0 : 0xFFFFFF;
	if (is_comma(split[i]) ? i += 3 : i)
	{
		shift = 20;
		while (split[i])
		{
			if (is_digit(split[i]))
				map[height][width].color |= ((split[i] - 48) << shift);
			else if (is_alphabet(split[i]) == UPPERCASE)
				map[height][width].color |= ((10 + (split[i] - 65)) << shift);
			else if (is_alphabet(split[i]) == LOWERCASE)
				map[height][width].color |= ((10 + (split[i] - 97)) << shift);
			shift -= 4;
			i += 1;
		}
	}
}

t_u			check_hexad(t_u i, t_u j, char **split, t_pnt **map)
{
	t_u letters_count;

	letters_count = 0;
	while (split[i][j])
	{
		if (!is_alphabet(split[i][j]) && !is_digit(split[i][j]))
			error_file_no_valid(split, map);
		letters_count += 1;
		j += 1;
	}
	if (letters_count > 6)
		error_file_no_valid(split, map);
	return (1);
}

void		check_values(char **split, t_pnt **map, t_u height, t_u width)
{
	t_u i;
	t_u j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!j && is_sign(split[i][j]))
				j += 1;
			else if (is_digit(split[i][j]))
				j += 1;
			else if (j && (is_comma(split[i][j]) && split[i][j + 1]) &&
					(split[i][j + 1] == '0' && split[i][j + 2]) &&
					(is_x(split[i][j + 2])) &&
					(check_hexad(i, j + 3, split, map)))
				break ;
			else
				error_file_no_valid(split, map);
		}
		write_values(height, width, split[i], map);
		width += 1;
		i += 1;
	}
	// УДАЛИТЬ
	j = 0;
	while (j < width)
	{
		printf("%d,%x ", map[height][j].z, map[height][j].color);
		j += 1;
	}
	printf("\n");
	// УДАЛИТЬ
}

void		write_map(int fd, t_pnt **map)
{
	int		result_gnl;
	t_u		height;
	t_u		width;
	char	**split;
	char	*line;

	height = 0;
	width = 0;
	while ((result_gnl = get_next_line(fd, &line)))
	{
		error_gnl(result_gnl, line, map);
		width = 0;
		while ((line[width] = line[width] == TAB ? SPACE : line[width]))
			width += 1;
		if (!(split = ft_strsplit(line, SPACE)))
			error_split(line, map);
		width = 0;
		check_values(split, map, height, width);
		height += 1;
		ft_memrelease((void**)split);
		free(line);
	}
	free(line);
	close(fd);
}
