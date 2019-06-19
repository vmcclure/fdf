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

void	risuem_dlinniyy(t_cam *cam)
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
		if ((cam->x0+ cam->x00+(cam->y0 * cam->bigx+ cam->y00*cam->bigx) < cam->bigx * cam->bigy) && cam->x0+cam->x00 < cam->bigx && cam->x0+cam->x00 > 0)
			{
					cam->img_str[cam->x0+ cam->x00+(cam->y0 * cam->bigx+ cam->y00*cam->bigx)] = cam->color;
			}
			// mlx_pixel_put(cam->mlx_ptr, cam->win_ptr, cam->x0 + cam->x00,
			// cam->y0 + cam->y00, cam->color);
			cam->x0--;
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

void	stavim_tochkiy(t_cam *cam)
{
	cam->z = cam->map[cam->y1][cam->x1];
	cam->y0 = cam->y1 * cam->shagy;
	cam->x0 = cam->x1 * cam->shagx;
	cam->isox0 = ((cam->x0 - cam->y0) * cos(cam->ugolx)) * cam->zoom;
	cam->isox1 = ((((cam->x1) * cam->shagx) - ((cam->y1 + 1) * cam->shagy))
	* cos(cam->ugolx)) * cam->zoom;
	cam->isoy0 = ((cam->x0 + cam->y0) * sin(cam->ugoly) -
	(cam->z * cam->pz)) * cam->zoom;
	if (cam->y1 + 1 != cam->y)
		cam->isoy1 = ((((cam->x1) * cam->shagx) + ((cam->y1 + 1)
		* cam->shagy)) * sin(cam->ugoly) - (cam->map[cam->y1 + 1][cam->x1]
		* cam->pz)) * cam->zoom;
	cam->dy = (cam->isoy1 - cam->isoy0);
	cam->dx = (cam->isox1 - cam->isox0);
	if (cam->dy < 0)
		cam->e = -1;
	else
		cam->e = 1;
	cam->dy = abs(cam->dy);
	cam->dx = abs(cam->dx);
	if (cam->y1 + 1 == cam->y)
	{
		cam->dx = 0;
		cam->dy = 0;
	}
}

void	risuem_korotkiyy(t_cam *cam)
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
			// mlx_pixel_put(cam->mlx_ptr, cam->win_ptr, cam->x0 + cam->x00,
			// cam->y0 + cam->y00, cam->color);
			cam->y0 = cam->y0 + cam->e;
			cam->sumdx = cam->dx + cam->sumdx;
			if (cam->sumdx >= cam->dy)
			{
				cam->x0--;
				cam->sumdx = cam->sumdx - cam->dy;
			}
			cam->i++;
		}
	}
}
