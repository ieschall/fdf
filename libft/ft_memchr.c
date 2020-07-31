/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:21:43 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/20 21:55:19 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *str, int c, size_t num)
{
	unsigned char	*string;

	string = (unsigned char *)str;
	while (num != 0)
	{
		if (*string == (unsigned char)c)
			return (string);
		string++;
		num--;
	}
	return (NULL);
}
