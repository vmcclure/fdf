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
#include <math.h>

void	init(t_cam *cam)
{
	cam->k = 0;
	cam->x0 = 0;
	cam->x1 = 0;
	cam->y0 = 0;
	cam->y1 = 0;
	cam->shagx = cam->bigx / (cam->x);
	cam->shagy = cam->bigy / (cam->y);
	cam->i = 0;
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 2, 0, 0xfffff0, "zoom = +/-");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 2, 15, 0xfffff0,
	"red = R, green = G, blue = B. white = W");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 2, 30, 0xfffff0,
	"move = UP/DOWN/RIGHT/LEFT or LKM");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 2, 60, 0xfffff0,
	"iso/line = I/4");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 2, 45, 0xfffff0,
	"transform z = mouse wheel");
}

void	drow1(t_cam *cam)
{
	mlx_clear_window(cam->mlx_ptr, cam->win_ptr);
	init(&*cam);
	cam->mlx_img = mlx_new_image(cam->mlx_ptr,cam->bigx, cam->bigy);
	cam->img_str = (int *)mlx_get_data_addr (cam->mlx_img, &cam->bits_per_pixel, &cam->size_line, &cam->endian);
	while (cam->y1 < cam->y)
	{
		cam->x1 = 0;
		cam->y0 = cam->y1 * cam->shagy;
		cam->x0 = cam->x1 * cam->shagx;
		while (cam->x1 < cam->x)
		{
			stavim_tochkix(&*cam);
			risuem_dlinniyx(&*cam);
			risuem_korotkiyx(&*cam);
			stavim_tochkiy(&*cam);
			risuem_dlinniyy(&*cam);
			risuem_korotkiyy(&*cam);
			cam->x1++;
		}
		cam->y1++;
	}
}

void	risuem_korotkiyx(t_cam *cam)
{
	if (cam->dx < cam->dy)
	{
		cam->sumdx = 0;
		cam->sumdy = 0;
		cam->i = 0;
		while (cam->i < cam->dy)
		{
			if (cam->i == 0)
			{
				cam->y0 = cam->isoy0;
				cam->x0 = cam->isox0;
			}
					if ((cam->x0+ cam->x00+(cam->y0 * cam->bigx+ cam->y00*cam->bigx) < cam->bigx * cam->bigy) && cam->x0+cam->x00 < cam->bigx && cam->x0+cam->x00 > 0)
			{
					cam->img_str[cam->x0+ cam->x00+(cam->y0 * cam->bigx+ cam->y00*cam->bigx)] = cam->color;
			}
			// mlx_pixel_put(cam->mlx_ptr, cam->win_ptr, cam->x0
			// + cam->x00, cam->y0 + cam->y00, cam->color);
			 cam->y0 = cam->y0 + cam->e;
			 cam->sumdx = cam->dx + cam->sumdx;
			if (cam->sumdx >= cam->dy)
			{
				cam->x0++;
				cam->sumdx = cam->sumdx - cam->dy;
			}
			cam->i++;
		}
	}
}

void	risuem_dlinniyx(t_cam *cam)
{
	if (cam->dx >= cam->dy)
	{
		cam->sumdx = 0;
		cam->sumdy = 0;
		cam->i = 0;
		while (cam->i <= cam->dx)
		{
			if (cam->i == 0)
			{
				cam->y0 = cam->isoy0;
				cam->x0 = cam->isox0;
			}
			if ((cam->x0+ cam->x00+(cam->y0 * cam->bigx+ cam->y00*cam->bigx) < cam->bigx * cam->bigy) && cam->x0+cam->x00 < cam->bigx)		if ((cam->x0+ cam->x00+(cam->y0 * cam->bigx+ cam->y00*cam->bigx) < cam->bigx * cam->bigy) && cam->x0+cam->x00 < cam->bigx && cam->x0+cam->x00 > 0)
			{
					cam->img_str[cam->x0+ cam->x00+(cam->y0 * cam->bigx+ cam->y00*cam->bigx)] = cam->color;
			}
			// mlx_pixel_put(cam->mlx_ptr, cam->win_ptr, cam->x0 +
			// cam->x00, cam->y0 + cam->y00, cam->color);
			cam->x0++;
			cam->sumdy = cam->dy + cam->sumdy;
			if (cam->sumdy >= cam->dx)
			{
				cam->y0 = cam->y0 + cam->e;
				cam->sumdy = cam->sumdy - cam->dx;
			}
			cam->i++;
		}
	}
}

void	stavim_tochkix(t_cam *cam)
{
	cam->z = cam->map[cam->y1][cam->x1];
	cam->y0 = cam->y1 * cam->shagy;
	cam->x0 = cam->x1 * cam->shagx;
	cam->isox0 = ((cam->x0 - cam->y0) * cos(cam->ugolx) * cam->zoom);
	if (cam->x1 + 1 != cam->x)
		cam->isox1 = ((((cam->x1 + 1) * cam->shagx) - ((cam->y1) * cam->shagy))
		* cos(cam->ugolx)) * cam->zoom;
	cam->isoy0 = ((cam->x0 + cam->y0) * sin(cam->ugoly) -
	(cam->z * cam->pz)) * cam->zoom;
	cam->isoy1 = ((((cam->x1 + 1) * cam->shagx) + ((cam->y1) * cam->shagy))
	* sin(cam->ugoly) - (cam->map[cam->y1][cam->x1 + 1] * cam->pz)) * cam->zoom;
	cam->dy = (cam->isoy1 - cam->isoy0);
	cam->dx = (cam->isox1 - cam->isox0);
	if (cam->dy < 0)
		cam->e = -1;
	else
		cam->e = 1;
	cam->dy = abs(cam->dy);
	cam->dx = abs(cam->dx);
	if (cam->x1 + 1 == cam->x)
	{
		cam->dx = 0;
		cam->dy = 0;
	}
}
