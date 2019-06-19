/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:02:45 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/20 19:12:16 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str, const void *source, size_t len)
{
	size_t i;

	i = len;
	if (str == NULL && source == NULL && len > 0)
		return (NULL);
	while (len--)
	{
		*(unsigned char *)str = *(unsigned char *)source;
		str++;
		source++;
	}
	return (str - i);
}
