/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 05:13:52 by ieschall          #+#    #+#             */
/*   Updated: 2019/09/26 21:39:10 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		length;
	int		i;
	char	*string;

	length = ft_strlen(s);
	if (!(string = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		string[i] = (*f)(s[i]);
		i++;
	}
	return (string);
}
