/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:25:40 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/02 16:25:42 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	slova(char *s, char c)
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

static	char	**ft_deldel(char **str, size_t y)
{
	while (y > 0)
	{
		free(str[y]);
		y--;
	}
	free(*str);
	free(str);
	str = NULL;
	return (str);
}

static	char	**ft_hz(char *s, char c, char **str)
{
	size_t		i;
	char		*start;

	i = 0;
	start = (char *)s;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (s != start)
			{
				str[i] = ft_strsub(start, 0, s - start);
				if (!str[i])
					return (ft_deldel(str, i));
				i++;
			}
			start = (char *)s + 1;
		}
		s++;
	}
	if (*s == '\0' && s != start)
		str[i++] = ft_strsub(start, 0, s - start);
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		y;

	y = slova((char *)s, c);
	if (!s || !c)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * y + 1);
	if (!str)
		return (NULL);
	str[y] = NULL;
	str = ft_hz((char *)s, c, str);
	return (str);
}
