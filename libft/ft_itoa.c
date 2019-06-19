/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:11:50 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/03 15:11:53 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_strnum(int n)
{
	int			len;
	int			i;

	if (n < 0)
		n = n * -1;
	i = 1;
	len = 1;
	while (i <= n / 10)
	{
		i = i * 10;
		len++;
	}
	return (len);
}

static	char	*zabivaka(int i, int n, int e, char *str)
{
	while (i != 0)
	{
		str[e] = (n / i + '0');
		n = n % i;
		i = i / 10;
		e++;
	}
	str[e] = '\0';
	return (str);
}

static	char	*stroka(int *n, int *e)
{
	char		*str;

	str = ft_memalloc(ft_strnum(*n) + 2);
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	*n = 147483648;
	*e = 2;
	return (str);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*str;
	int			e;

	e = 0;
	i = 1;
	if (n == -2147483648)
		str = stroka(&n, &e);
	else if (n < 0)
	{
		str = ft_memalloc(ft_strnum(n) + 2);
		if (!str)
			return (NULL);
		str[e++] = '-';
		n = (n * (-1));
	}
	else
	{
		str = ft_memalloc(ft_strnum(n) + 1);
		if (!str)
			return (NULL);
	}
	while (i <= n / 10)
		i = i * 10;
	return (zabivaka(i, n, e, str));
}
