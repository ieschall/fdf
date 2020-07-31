/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_memory_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:45:16 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/30 22:45:57 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_u			check_rect(char *line, char **av, t_u digit_count, t_u width)
{
	if (digit_count && width && digit_count != width)
	{
		free(line);
		error(ERR_FILE_NO_VALID, av);
	}
	if (!width && digit_count)
	{
		width = digit_count;
		return (width);
	}
	if (!width && !digit_count)
	{
		free(line);
		error(ERR_FILE_NO_VALID, av);
	}
	return (0);
}

t_u			get_digit_count(char *line)
{
	t_u		i;
	char	**arr_split;

	i = 0;
	while ((line[i] = line[i] == TAB ? SPACE : line[i]))
		i += 1;
	if (!(arr_split = ft_strsplit(line, SPACE)))
	{
		free(line);
		error(ERR_NO_MEMORY, NULL);
	}
	i = 0;
	while (arr_split[i])
		i += 1;
	ft_memrelease((void**)arr_split);
	return (i);
}

t_u			get_width(int fd, char **av)
{
	int		result_gnl;
	t_u		digit_count;
	t_u		width;
	char	*line;

	width = 0;
	while ((result_gnl = get_next_line(fd, &line)))
	{
		error_gnl(result_gnl, line, NULL);
		digit_count = get_digit_count(line);
		if (check_rect(line, av, digit_count, width))
			width = digit_count;
		free(line);
	}
	free(line);
	close(fd);
	return (width);
}

t_u			get_height(int fd)
{
	int		result_gnl;
	t_u		height;
	char	*line;

	height = 0;
	while ((result_gnl = get_next_line(fd, &line)))
	{
		error_gnl(result_gnl, line, NULL);
		free(line);
		height += 1;
	}
	free(line);
	close(fd);
	return (height);
}
