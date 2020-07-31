/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrelease.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:21:36 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/19 19:22:30 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memrelease(void **str)
{
	unsigned	count;

	count = 0;
	while (str[count])
		free(str[count++]);
	free(str);
}
