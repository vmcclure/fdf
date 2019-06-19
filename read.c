/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 07:39:15 by vmcclure          #+#    #+#             */
/*   Updated: 2019/02/03 07:39:19 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	move(t_cam *cam)
{
	if (cam->str[cam->i] == '-')
		cam->i++;
	while (cam->ati / 10 != 0)
	{
		cam->ati = cam->ati / 10;
		cam->i++;
	}
}

int		ft_read(t_cam *cam, char **argv)
{
	cam->e = 1;
	cam->i = 0;
	cam->x = 0;
	cam->y = 1;
	cam->str = ft_memalloc(1);
	if ((cam->fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	while ((cam->size = read(cam->fd, cam->buf, 100)) > 0)
	{
		cam->buf[cam->size] = '\0';
		if (!(cam->str = ft_strjoin(cam->str, cam->buf)))
			return (0);
	}
	while (cam->str[cam->i])
	{
		if (cam->str[cam->i] == '\n' && cam->str[cam->i + 1] == '\n')
			return (0);
		if (cam->str[cam->i] == '\n' && cam->str[cam->i + 1] != '\0')
			cam->y++;
		cam->i++;
	}
	cam->i = 0;
	return (1);
}

int		save_num(t_cam *cam)
{
	if (cam->y1 == cam->y - 1)
		cam->k = 0;
	if ((cam->str[cam->i] >= '0' && cam->str[cam->i] <= '9')
	|| cam->str[cam->i] == '-')
	{
		cam->k = 1;
		if (cam->x1 >= cam->x)
			return (0);
		cam->map[cam->y1][cam->x1] = ft_atoi(cam->str + cam->i);
		cam->ati = cam->map[cam->y1][cam->x1];
		move(cam);
		cam->i++;
		cam->x1++;
	}
	else if (cam->str[cam->i] == ' ' || cam->str[cam->i] == '\n')
		cam->i++;
	else
		return (0);
	if (cam->str[cam->i] == '\n')
		cam->k = 1;
	return (1);
}

int		newx(t_cam *cam)
{
	cam->x1 = 0;
	cam->map[cam->y1] = (int *)malloc(sizeof(int) * cam->x + 1);
	if (!cam->map[cam->y1])
		return (0);
	cam->map[cam->y1][cam->x] = 0;
	while (cam->str[cam->i] != '\n' && cam->str[cam->i] != '\0')
		if (!(save_num(&*cam)))
			return (0);
	if (((cam->str[cam->i] == '\n' || cam->str[cam->i] == '\0')
	&& cam->x1 != cam->x && cam->x1 > 0) || cam->k == 0)
		return (0);
	cam->i++;
	cam->y1++;
	return (1);
}

int		vali(t_cam *cam, char **argv)
{
	if (!(ft_read(&*cam, argv)))
		return (0);
	cam->map = (int **)malloc(sizeof(int *) * (cam->y + 1));
	cam->map[cam->y] = NULL;
	while (cam->str[cam->i] != '\n' && cam->str[cam->i] != '\0')
	{
		if (cam->str[cam->i] >= '0' && cam->str[cam->i] <= '9' &&
		(cam->str[cam->i + 1] < '0' || cam->str[cam->i + 1] > '9'))
			cam->x++;
		cam->i++;
	}
	cam->i = 0;
	cam->y1 = 0;
	while (cam->y1 < cam->y)
	{
		if (!(newx(&*cam)))
			return (0);
	}
	cam->mlx_ptr = mlx_init();
	cam->win_ptr = mlx_new_window(cam->mlx_ptr, cam->bigx, cam->bigy, "hello");
	drow1(&*cam);
	return (1);
}
