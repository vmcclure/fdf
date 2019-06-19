/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:01:49 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 17:01:51 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	unsigned long long	i;
	int					sign;

	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'\
		|| *str == '\r' || *str == '\v' || *str == '\f')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		if (i != i * 10 / 10)
			return (sign == 1 ? -1 : 0);
		i = i * 10 + *str - '0';
		str++;
	}
	return (i * sign);
}
