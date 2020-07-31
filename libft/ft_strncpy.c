/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 03:09:40 by ieschall          #+#    #+#             */
/*   Updated: 2019/10/01 18:45:38 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *str, size_t num)
{
	size_t i;

	i = 0;
	while (i < num && str[i])
	{
		destination[i] = str[i];
		i++;
	}
	while (i < num)
		destination[i++] = '\0';
	return (destination);
}
