/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:08:02 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/30 22:40:07 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_split(char *line, t_pnt **map)
{
	free(line);
	ft_memrelease((void**)map);
	error(ERR_NO_MEMORY, NULL);
}

void	error_file_no_valid(char **arr_split, t_pnt **map)
{
	ft_memrelease((void**)arr_split);
	ft_memrelease((void**)map);
	ft_putendl_fd("\033[1;31mError:\033[0m file is not valid", STDERR_FILENO);
	exit(ERR_FILE_NO_VALID);
}

void	error_gnl(int result_gnl, char *line, t_pnt **map)
{
	if (result_gnl < 0 && !map)
	{
		free(line);
		ft_putstr_fd("\033[1;31mError:\033[0m get_next_line", STDERR_FILENO);
		ft_putendl_fd(" returned \033[1;35m-1\033[0m", STDERR_FILENO);
		exit(ERR);
	}
	else if (result_gnl < 0 && map)
	{
		free(line);
		ft_memrelease((void**)map);
		ft_putstr_fd("\033[1;31mError:\033[0m get_next_line", STDERR_FILENO);
		ft_putendl_fd(" returned \033[1;35m-1\033[0m", STDERR_FILENO);
		exit(ERR);
	}
}

void	error(int code, char **av)
{
	if (code == ERR_NO_PARAM)
	{
		ft_putstr_fd("\033[1;31mError:\033[0m \033[1;35m", STDERR_FILENO);
		ft_putstr_fd(av[0], STDERR_FILENO);
		ft_putendl_fd("\033[0m usage without parameter", STDERR_FILENO);
	}
	else if (code == ERR_NO_FILE)
	{
		ft_putstr_fd("\033[1;31mError:\033[0m opening file", STDERR_FILENO);
		ft_putstr_fd(" \033[1;35m", STDERR_FILENO);
		ft_putstr_fd(av[1], STDERR_FILENO);
		ft_putendl_fd("\033[0m", STDERR_FILENO);
	}
	else if (code == ERR_FILE_NO_VALID)
	{
		ft_putstr_fd("\033[1;31mError:\033[0m file \033[1;35m", STDERR_FILENO);
		ft_putstr_fd(av[1], STDERR_FILENO);
		ft_putendl_fd("\033[0m is not valid", STDERR_FILENO);
	}
	else if (code == ERR_NO_MEMORY)
		ft_putendl("\033[1;31mMalloc error\033[0m");
	else
		ft_putendl("\033[1;31mError\033[0m");
	exit(code);
}
