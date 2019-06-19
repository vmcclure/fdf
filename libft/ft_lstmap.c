/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:39:13 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/04 21:39:15 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *start;

	if (!lst)
		return (NULL);
	if (!f)
		return (NULL);
	list = f(lst);
	start = list;
	while (lst)
	{
		lst = lst->next;
		list->next = f(lst);
		if (!list->next)
		{
			free(list->next);
			return (NULL);
		}
		if (!(lst->next))
			return (start);
		list = list->next;
	}
	return (start);
}
