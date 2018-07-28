/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:17:48 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/25 22:17:50 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define WIN_H 600
# define WIN_W 800
# define PI 3.14159265
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			color;

}				t_line;

typedef struct	s_xyz
{
	int			x;
	int			y;
	int			z;
	float		xt;
	float		yt;
	float		zt;
}				t_xyz;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	float		ang;
	int			col;
	int			row;
	int			max_h;
	int			min_h;
	float		max_x;
	float		min_x;
	float		max_y;
	float		min_y;
	float		scale;
	int			center_c;
	int			center_r;
	t_xyz		**map;
}				t_mlx;

void			calibrate(t_mlx *m);
void			setup(t_mlx *m);
int				key_handler(int k, t_mlx *m);
int				mouse_handler(int button, int x, int y, t_mlx *m);
void			draw(t_mlx *m);
void			rotate(t_mlx *m, int mode, double rad);
void			scale(t_mlx *m, int k, double sc);
void			shift(t_mlx *m, int k, int unit);
void			stretch(t_mlx *m, int k, double scale);
void			draw_line(t_mlx *m, t_line l);
#endif
