/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:27:03 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 18:27:11 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t k;
	size_t e;

	e = len;
	k = ft_strlen(s2);
	if (len > k)
		len = k;
	i = 0;
	while (len--)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < e)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
