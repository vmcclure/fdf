/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:07:37 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 18:07:41 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*mass;
	size_t	i;

	i = 0;
	if ((mass = (char *)malloc(ft_strlen(str) + 1)) == NULL)
		return (0);
	while (str[i])
	{
		mass[i] = str[i];
		i++;
	}
	mass[i] = str[i];
	return (mass);
}
