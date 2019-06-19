/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:26:32 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 15:26:33 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	if (!str && !c && !len)
		return (NULL);
	while (len--)
	{
		if (*(char *)str == (char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
