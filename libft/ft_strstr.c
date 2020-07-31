/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:14:45 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/22 00:24:34 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_main_ft(const char *str1, const char *str2, size_t length)
{
	size_t	back;
	char	*string;

	while (*str1)
	{
		if (*str2 == *str1)
		{
			string = (char *)str1;
			back = 0;
			while (*str2)
			{
				if (*str2 != *str1)
				{
					str2 = str2 - back;
					str1 = str1 - 1;
					break ;
				}
				str2++;
				str1++;
				back++;
			}
		}
		str1++;
	}
	return (back != length || length == 0 ? NULL : string);
}

char			*ft_strstr(const char *str1, const char *str2)
{
	size_t	length;

	if (str2[0] == '\0')
		return ((char *)str1);
	length = ft_strlen(str2);
	return (ft_main_ft(str1, str2, length));
}
