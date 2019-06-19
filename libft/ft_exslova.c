/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exslova.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:46:47 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/06 20:46:50 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_exslova(char *s, char c)
{
	size_t		start;
	size_t		slovo;

	slovo = 0;
	start = 0;
	if (!s || !c)
		return (0);
	while (*s != '\0' && *s == c)
	{
		s++;
		start++;
	}
	if (!*s)
		return (0);
	slovo = 1;
	while (*s != '\0')
	{
		if (*s == c && s[1] != c && s[1] != '\0')
			slovo++;
		s++;
		start++;
	}
	s = s - start;
	return (slovo);
}
