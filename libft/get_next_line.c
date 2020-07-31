/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:23:17 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/17 19:39:08 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_strchr_n(const char *str)
{
	int		n;
	char	c;

	n = 0;
	c = '\n';
	while (*str++)
		if (*str == c)
			n++;
	return (n);
}

int		ft_readed_fully(char **point_newline, char ***line)
{
	char	*symbol_n;
	char	*remember_and_free;

	if (!*point_newline)
		if (!*point_newline && (ft_strlen(**line) == 0))
			ft_memdel((void **)&**line);
		else
			return (1);
	else
	{
		**line = ft_strnew(0);
		symbol_n = ft_strchr(*point_newline, '\n');
		*symbol_n++ = '\0';
		remember_and_free = **line;
		**line = ft_strjoin(**line, *point_newline);
		ft_memdel((void **)&remember_and_free);
		remember_and_free = *point_newline;
		*point_newline = ft_strdup(symbol_n);
		ft_memdel((void **)&remember_and_free);
		return (1);
	}
	return (0);
}

int		ft_all_verify(char **point_newline, char ***line)
{
	if (*point_newline != NULL)
		if (ft_strchr_n(*point_newline) == 0)
			ft_memdel((**line = ft_strdup(*point_newline)) ? \
				(void **)&*point_newline : (void **)&*point_newline);
		else
			return (2);
	else
		**line = ft_strnew(0);
	return (0);
}

int		ft_end(char **point_newline, char **line, char **buf)
{
	char *remember_and_free;

	*point_newline = ft_strdup(*point_newline);
	remember_and_free = *line;
	*line = ft_strjoin(*line, *buf);
	ft_memdel((void **)&remember_and_free);
	ft_memdel((void **)&*buf);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			size_reading;
	char		*buf;
	static char *point_newline;
	char		*remember_and_free;

	if (line && ft_all_verify(&point_newline, &line) == 2)
		return (ft_readed_fully(&point_newline, &line));
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) || !line)
		return (-1);
	while ((size_reading = read(fd, buf, BUFF_SIZE)))
	{
		if (size_reading == -1)
			return (-1);
		buf[size_reading] = '\0';
		if ((point_newline = ft_strchr(buf, '\n')) != NULL)
		{
			*point_newline++ = '\0';
			return (ft_end(&point_newline, line, &buf));
		}
		remember_and_free = *line;
		*line = ft_strjoin(*line, buf);
		ft_memdel((void **)&remember_and_free);
	}
	ft_memdel((void **)&buf);
	return (ft_readed_fully(&point_newline, &line));
}
