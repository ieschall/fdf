/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:35:48 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/27 23:26:41 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_quantity_numbers(int n)
{
	int	quantity;
	int	summa;

	if (n == 0)
		return (1);
	quantity = 0;
	summa = n;
	while (n != 0)
	{
		n = n % 10;
		summa = summa / 10;
		n = summa;
		quantity++;
	}
	return (quantity);
}

char		*ft_itoa(int n)
{
	char	*string;
	int		quan_num;
	int		sign;
	int		summa;

	sign = (n < 0 ? -1 : 1);
	quan_num = ft_quantity_numbers(n) + 1 + (n < 0 ? 1 : 0);
	if (!(string = (char *)malloc(sizeof(char) * quan_num)))
		return (NULL);
	ft_bzero(string, quan_num);
	if (n == 0)
		string[0] = '0';
	quan_num = quan_num - 2;
	summa = n;
	while (n != 0)
	{
		n = n % 10;
		string[quan_num] = n * sign + '0';
		quan_num--;
		summa = summa / 10;
		n = summa;
	}
	if (sign < 0)
		string[quan_num] = '-';
	return (string);
}
