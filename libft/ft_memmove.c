/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:04:10 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 16:04:12 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = len;
	if (src >= dst)
	{
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
		return (dst - i);
	}
	else
		while (len--)
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	return (dst);
}
