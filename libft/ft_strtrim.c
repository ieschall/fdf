/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:52:49 by ieschall          #+#    #+#             */
/*   Updated: 2019/10/01 18:47:00 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char	*fresh;
	size_t	first;
	size_t	last;
	size_t	i;

	if (*s == '\0')
		return ((char *)s);
	first = 0;
	last = ft_strlen(s) - 1;
	while (s[first] != '\0' && (s[first] == ' ' \
		|| s[first] == '\n' || s[first] == '\t'))
		first++;
	if (first == last + 1)
		return (ft_strnew(1));
	while (s[last] == ' ' || s[last] == '\n' || s[last] == '\t')
		last--;
	if (!(fresh = (char *)malloc(sizeof(char) * (last - first + 2))))
		return (NULL);
	ft_bzero(fresh, (last - first + 2));
	i = 0;
	while (first <= last)
		fresh[i++] = s[first++];
	return (fresh);
}
