/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 00:05:39 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/22 00:13:15 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t num)
{
	size_t length;

	if (str2[0] == '\0')
		return ((char *)str1);
	length = ft_strlen(str2);
	while (*str1 && num >= length)
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, length) == 0)
			return ((char *)str1);
		str1++;
		num--;
	}
	return (NULL);
}
