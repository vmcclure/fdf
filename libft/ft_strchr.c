/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:38:57 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 20:38:59 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int k)
{
	while (*(char *)str != k && *(char *)str != '\0')
		str++;
	if (*(char *)str == k)
		return ((char *)str);
	return (NULL);
}
