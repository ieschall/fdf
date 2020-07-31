/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:31:21 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/28 02:32:18 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;
	int total;

	if ((nb == 0) || (nb < 0))
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	while (i < nb)
	{
		i++;
		total = i * i;
		if (total == nb)
			return (i);
	}
	return (0);
}
