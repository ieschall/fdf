/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 02:30:07 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/21 02:45:32 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		destination[i] = str[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
