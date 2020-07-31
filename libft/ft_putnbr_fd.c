/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:53:16 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/24 06:37:51 by ieschall         ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	char	string[12];
	int		quan_num;
	int		sign;
	int		summa;

	sign = (n < 0 ? -1 : 1);
	quan_num = ft_quantity_numbers(n) + 1 + (n < 0 ? 1 : 0);
	ft_bzero(string, 12);
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
	ft_putstr_fd(string, fd);
}
