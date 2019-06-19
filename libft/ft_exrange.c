/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:50:10 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/06 21:50:17 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_exrange(int min, int max)
{
	int	*str;
	int	i;
	int	z;

	z = 0;
	if (min >= max)
		return (NULL);
	i = max - min;
	str = (int *)malloc(i * 4);
	if (!str)
		return (NULL);
	while (min < max)
	{
		str[z] = min;
		min++;
		z++;
	}
	return (str);
}
