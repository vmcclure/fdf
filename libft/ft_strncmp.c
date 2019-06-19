/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:48:48 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 16:48:50 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t lin)
{
	if (lin == 0)
		return (0);
	while (*(char *)s1 && *(char *)s2 && *(char *)s1 == *(char *)s2 && lin != 1)
	{
		s1++;
		s2++;
		lin--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
