/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:38:44 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 20:38:59 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	k;

	if (!f)
		return (NULL);
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	k = 0;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	while (i--)
	{
		str[k] = (f(s[k]));
		k++;
	}
	str[k] = '\0';
	return (str);
}
