/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exconcatpar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:46:06 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/06 21:46:07 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_exconcatpar(size_t argc, char **argv)
{
	char		*args;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		mem;

	mem = 0;
	i = 1;
	while (i < argc)
		mem = mem + ft_strlen(argv[i++]) + 1;
	args = (char*)malloc(sizeof(char) * mem);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			args[k++] = argv[i][j++];
		if (i == argc - 1)
			args[k++] = '\0';
		else
			args[k++] = '\n';
		i++;
	}
	return (args);
}
