/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:18:51 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/20 19:43:45 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str, const void *source, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)str = *(unsigned char *)source;
		if (*(unsigned char *)str == (unsigned char)c)
			return (str + 1);
		str++;
		source++;
	}
	return (NULL);
}
