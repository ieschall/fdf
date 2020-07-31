/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:27:21 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/26 20:46:33 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *str, size_t num)
{
	char		*dest;
	const char	*string;

	dest = (char *)destination;
	string = (const char *)str;
	if (str >= destination)
	{
		while (num != 0)
		{
			*dest = *string;
			string++;
			dest++;
			num--;
		}
	}
	else
	{
		while (num != 0)
		{
			dest[num - 1] = string[num - 1];
			num--;
		}
	}
	return (destination);
}
