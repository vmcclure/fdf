/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:54:35 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/02 13:54:37 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	k;
	char	*str;

	str = NULL;
	if (!s)
		return (NULL);
	k = ft_strlen(s);
	if (start + len <= k)
	{
		str = (char *)malloc(len + 1);
		if (!str)
			return (NULL);
		if (str)
		{
			str = ft_strncpy(str, (char *)s + start, len);
		}
		str[len] = '\0';
	}
	return (str);
}
