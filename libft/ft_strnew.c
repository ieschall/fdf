/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 03:59:27 by ieschall          #+#    #+#             */
/*   Updated: 2019/10/17 03:05:40 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	if (size + 1 < size)
		return (NULL);
	if (!(fresh = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(fresh, size + 1);
	return (fresh);
}
