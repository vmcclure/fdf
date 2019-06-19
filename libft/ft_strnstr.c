/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:53:40 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 14:53:42 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft1_memcmp(const void *s1, const void *s2, size_t n, size_t l)
{
	size_t e;

	e = 0;
	while (n--)
	{
		if (l <= e)
			return (1);
		if (*(unsigned char *)s1 != (*(unsigned char *)s2))
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		e++;
	}
	return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;

	i = len;
	while (*(char *)s1 != '\0' && len != 0)
	{
		if (ft1_memcmp(s1, s2, ft_strlen(s2), len) == 0)
			return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
