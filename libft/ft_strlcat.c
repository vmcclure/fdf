/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:42:49 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 19:42:50 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t k;
	size_t e;

	i = 0;
	e = ft_strlen(s2);
	k = ft_strlen(s1);
	if (k < len)
		ft_strncat(s1, s2, len - k - 1);
	if (k >= len)
		return (len + e);
	return (k + e);
}
