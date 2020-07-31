/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 03:29:42 by ieschall          #+#    #+#             */
/*   Updated: 2019/10/01 18:39:58 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *str)
{
	int	i;
	int	j;

	i = (int)ft_strlen(destination);
	j = 0;
	while (str[j])
		destination[i++] = str[j++];
	destination[i] = '\0';
	return (destination);
}
