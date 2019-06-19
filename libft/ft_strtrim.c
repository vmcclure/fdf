/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:46:04 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/02 14:46:05 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	while ((*(char *)s == ' ' || *(char *)s == '\t' ||
		*(char *)s == '\n') && *(char *)s != '\0')
		s++;
	if (!*s)
		return (ft_strnew(1));
	len = ft_strlen((char *)s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, (char *)s, len + 1);
	return (str);
}
