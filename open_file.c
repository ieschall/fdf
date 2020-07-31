/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:07:16 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/21 20:07:42 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		open_file(char **av)
{
	int fd;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		error(ERR_NO_FILE, av);
	if (read(fd, NULL, 0) < 0)
		error(ERR_FILE_NO_VALID, av);
	return (fd);
}
