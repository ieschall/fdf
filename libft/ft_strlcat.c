/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 03:51:28 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/21 18:07:31 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *str, size_t num)
{
	size_t	dest_i;
	size_t	string_i;
	size_t	result;
	size_t	i;

	dest_i = ft_strlen(destination);
	string_i = ft_strlen(str);
	if (num <= dest_i)
		result = num + string_i;
	else
		result = dest_i + string_i;
	i = 0;
	while (str[i] && dest_i + 1 < num)
		destination[dest_i++] = str[i++];
	destination[dest_i] = '\0';
	return (result);
}
