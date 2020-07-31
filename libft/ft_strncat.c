/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 03:38:37 by ieschall          #+#    #+#             */
/*   Updated: 2019/10/01 18:45:05 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, char *str, size_t num)
{
	size_t	i;
	size_t	j;

	i = (int)ft_strlen(destination);
	j = 0;
	while (j < num && str[j])
		destination[i++] = str[j++];
	destination[i] = '\0';
	return (destination);
}
