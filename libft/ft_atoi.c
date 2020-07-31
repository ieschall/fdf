/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 01:56:41 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/30 13:38:54 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	n;
	int symb;

	while ((*str == ' ') || (*str == '\t') || (*str == '\n') || \
			(*str == '\r') || (*str == '\v') || (*str == '\f'))
		str++;
	symb = 1;
	if (*str == '-')
		symb = -1;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = 10 * n + (*str - '0');
		str++;
	}
	return (symb * n);
}
