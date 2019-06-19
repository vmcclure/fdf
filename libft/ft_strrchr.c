/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:29:36 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 21:29:37 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int k)
{
	size_t e;

	e = ft_strlen(str);
	str = str + e;
	while (*(char *)str != k && e != 0)
	{
		str--;
		e--;
	}
	if (*(char *)str == k)
		return ((char *)str);
	return (NULL);
}
