/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:29:54 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/21 20:12:55 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*string;

	string = (char *)str;
	if (ft_strchr(str, c) == NULL)
		return (NULL);
	while (*string)
		string++;
	while (*string != (char)c)
		string--;
	return (string);
}
