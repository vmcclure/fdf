/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:30:47 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/04 21:30:49 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (!content)
	{
		list->content_size = 0;
		list->content = NULL;
		list->next = NULL;
		return (list);
	}
	list->content = ft_memcpy(ft_memalloc(content_size), (void *)content,
		content_size);
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
