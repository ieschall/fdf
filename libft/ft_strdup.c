/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:01:36 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/27 23:28:40 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*string;
	size_t	length;
	size_t	i;

	length = ft_strlen(str);
	if (!(string = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	string[length] = '\0';
	i = 0;
	while (i < length)
	{
		string[i] = str[i];
		i++;
	}
	return (string);
}
