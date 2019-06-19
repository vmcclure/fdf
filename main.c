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


int		ft_mouse(int k, int x1, int y1, t_cam *cam)
{
	printf("%d\n", k);
		cam->key = k;
	if (k == 1)
	{
		cam->x00 = x1;
		cam->y00 = y1;
		drow1(&*cam);
		mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, cam->mlx_img, 0, 0);
	}
	if (k == 4)
	{
		cam->pz--;
		drow1(&*cam);
		mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, cam->mlx_img, 0, 0);
	}
	if (k == 5)
	{
		cam->pz++;
		drow1(&*cam);
		mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, cam->mlx_img, 0, 0);
	}
	return (0);
}
int		ft_mouse1(int x1, int y1, t_cam *cam)
{
	//mlx_pixel_put(cam->mlx_ptr, cam->win_ptr, x1, y1, 0xffffff);
	if (cam->key == 1)
	{
		cam->x00 = x1;
		cam->y00 = y1;
		drow1(&*cam);
	}
//	cam->key = 0;
		// cam->x00 = x1;
		// cam->y00 = y1;
		// //drow1(&*cam);
		// mlx_hook(cam->win_ptr, 4, 0, ft_mouse, &cam);
		// mlx_loop(cam->mlx_ptr);
		// mlx_hook(cam->win_ptr, 4, 0, ft_mouse, &cam);
	return (0);
}

int		tkeycolor(int key, t_cam *cam)
{
	if (key == 21)
		drow2(&*cam);
	if (key == 5)
		cam->color = 0x00FF00;
	if (key == 15)
		cam->color = 0xFF0000;
	if (key == 11)
		cam->color = 0x0000FF;
	if (key == 13)
		cam->color = 0xffffFF;
	if (key == 34)
		cam->ugoly = 0.523599;
	if (key == 37)
		cam->ugoly = 0;
	if (key == 5 || key == 15 || key == 11 || key == 13 ||
	key == 37 || key == 34)
		drow1(&*cam);
	mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, cam->mlx_img, 0, 0);
	return (0);
}

int		tkey(int key, t_cam *cam)
{

	if (key == 53)
		exit(0);
	tkeycolor(key, &*cam);
	if (key == 69 && cam->zoom < 64)
		cam->zoom *= 2;
	if (key == 78)
		if (cam->zoom > 0.0001)
			cam->zoom /= 2;
	if (key == 126)
		cam->y00 -= 30;
	if (key == 125)
		cam->y00 += 30;
	if (key == 123)
		cam->x00 -= 30;
	if (key == 124)
		cam->x00 += 30;
	if (key == 87)
		cam->ugoly += 0.1;
	if (key == 84)
		cam->ugoly -= 0.1;
	if ((key == 69 || key == 78 || key == 126 || key == 125 || key == 123
	|| key == 124 || key == 87 || key == 84) && cam->zoom <= 64)
		drow1(&*cam);
		mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, cam->mlx_img, 0, 0);
	return (0);
}

void	drow2(t_cam *cam)
{
	mlx_clear_window(cam->mlx_ptr, cam->win_ptr);
	init(&*cam);
	cam->shagx = cam->shagx * 0.9;
	cam->shagy = cam->shagy * 0.9;
	while (cam->y1 < cam->y)
	{
		cam->x1 = 0;
		while (cam->x1 < cam->x)
		{
			cam->i = -1;
			while (cam->i++ < cam->shagx && cam->x1 != cam->x - 1)
				mlx_pixel_put(cam->mlx_ptr, cam->win_ptr, (cam->x1 * cam->shagx
				+ cam->i) + 100, (cam->y1 * cam->shagy) + 100, cam->color);
			cam->i = -1;
			while (cam->i++ < cam->shagy && cam->y1 != cam->y - 1)
				mlx_pixel_put(cam->mlx_ptr, cam->win_ptr, (cam->x1 * cam->shagx)
				+ 100, (cam->y1 * cam->shagy + cam->i) + 100, cam->color);
			cam->x1++;
		}
		cam->y1++;
	}
}

int		main(int argc, char **argv)
{
	t_cam cam;

	cam.bigx = 1560;
	cam.bigy = 1300;
	cam.color = 0xFFFFFF;
	cam.ugolx = 0.523599;
	cam.ugoly = 0.523599;
	cam.zoom = 0.5;
	cam.pz = 1;
	cam.y00 = cam.bigy / 10;
	cam.x00 = cam.bigx / 2;
	if (argc != 2)
		return (0);
	if (!vali(&cam, argv))
	{
		ft_putstr("ERROR!!!");
		return (0);
	}
	cam.mlx_img = mlx_new_image(cam.mlx_ptr,cam.bigx, cam.bigy);
	cam.img_str = (int *)mlx_get_data_addr (cam.mlx_img, &cam.bits_per_pixel, &cam.size_line, &cam.endian);
	mlx_put_image_to_window(cam.mlx_ptr, cam.win_ptr, cam.mlx_img, 0, 0);
	mlx_hook(cam.win_ptr, 4, 0, ft_mouse, &cam);
	//mlx_hook(cam.win_ptr, 6, 0, ft_mouse1, &cam);
	mlx_hook(cam.win_ptr, 2, 0, tkey, &cam);
	mlx_loop(cam.mlx_ptr);
	return (0);
}
