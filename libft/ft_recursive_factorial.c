/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 03:15:51 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/28 03:16:21 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	if ((nb == 0) || (nb == 1))
		return (1);
	if ((nb < 0) || (nb > 12))
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
