/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:23:52 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 20:23:53 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;
	size_t k;

	if (!f)
		return ;
	if (!s)
		return ;
	k = 0;
	i = ft_strlen(s);
	while (i--)
	{
		(f(k, s));
		s++;
		k++;
	}
}
