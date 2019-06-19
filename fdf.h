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

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct			s_cam
{
	int		key;
	int bits_per_pixel;
	int size_line;
	int endian;
	int *img_str;
	void	*mlx_img;
	int		pz;
	void	*mlx_ptr1;
	void	*win_ptr1;
		void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	char	buf[101];
	int		x;
	int		y;
	int		i;
	int		size;
	char	*str;
	int		y1;
	int		**map;
	int		x1;
	int		ati;
	int		k;
	int		y0;
	int		x0;
	int		dx;
	int		dy;
	int		sumdy;
	int		shagx;
	int		e;
	int		shagy;
	int		sumdx;
	int		z;
	int		isox0;
	int		isoy0;
	int		isox1;
	int		isoy1;
	int		argc;
	char	**argv;
	int		x00;
	int		y00;
	float	zoom;
	float	ugolx;
	float	ugoly;
	int		color;
	int		startx;
	int		starty;
	int		bigx;
	int		bigy;
}						t_cam;
void					risuem_korotkiyx(t_cam *cam);
void					risuem_dlinniyx(t_cam *cam);
void					stavim_tochkix(t_cam *cam);
void					risuem_dlinniyy(t_cam *cam);
void					stavim_tochkiy(t_cam *cam);
void					risuem_korotkiyy(t_cam *cam);
void					drow2(t_cam *cam);
void					drow1(t_cam *cam);
void					init(t_cam *cam);
int						ft_read(t_cam *cam, char **argv);
int						save_num(t_cam *cam);
int						newx(t_cam *cam);
int						vali(t_cam *cam, char **argv);

#endif
