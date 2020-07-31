/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:45:29 by ieschall          #+#    #+#             */
/*   Updated: 2020/07/30 22:45:32 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_digit(int с)
{
	return (с >= '0' && '9' >= с);
}

int		is_sign(int с)
{
	return (с == '-' || с == '+');
}

int		is_alphabet(int с)
{
	if (с >= 'a' && 'f' >= с)
		return (1);
	if (с >= 'A' && 'F' >= с)
		return (2);
	return (0);
}

int		is_x(int c)
{
	return (c == 'x' || c == 'X');
}

int		is_comma(int c)
{
	return (c == ',');
}
