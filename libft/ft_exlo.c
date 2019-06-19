/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exlo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:53:55 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/06 20:53:56 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_exlo(char *str)
{
	int		i;
	char	*c;

	c = (char *)malloc(ft_strlen(str) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (str[i])
	{
		c[i] = ft_tolower(str[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
