/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:12:09 by ieschall          #+#    #+#             */
/*   Updated: 2019/10/01 19:35:27 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list *lst)
{
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
	lst = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	if (!(new = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
	{
		ft_free(new);
		return (NULL);
	}
	first = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
		{
			ft_free(first);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
