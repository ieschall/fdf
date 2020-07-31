/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:25:30 by ieschall          #+#    #+#             */
/*   Updated: 2019/10/01 18:37:00 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *str, int c, size_t num)
{
	unsigned char	*destan;
	unsigned char	*string;

	destan = (unsigned char *)dest;
	string = (unsigned char *)str;
	while (num != 0)
	{
		*destan = *string;
		if (*string == (unsigned char)c)
			return (destan + 1);
		destan++;
		string++;
		num--;
	}
	return (NULL);
}
