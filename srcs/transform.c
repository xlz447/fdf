/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:43:11 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/26 23:43:34 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		scale(t_mlx *m, int k, double sc)
{
	int	r;
	int	c;

	if (k == 4)
		sc = 1 / sc;
	r = -1;
	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
		{
			m->map[r][c].xt *= sc;
			m->map[r][c].yt *= sc;
			m->map[r][c].zt *= sc;
		}
	}
}

void		shift(t_mlx *m, int k, int unit)
{
	int	r;
	int	c;

	if (k == 123 || k == 126)
		unit *= -1;
	r = -1;
	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
		{
			if (k == 123 || k == 124)
				m->map[r][c].xt += unit;
			else if (k == 125 || k == 126)
				m->map[r][c].yt += unit;
		}
	}
}

static void	rotate_help(int mode, double rad, t_xyz *xyz)
{
	float	xt;
	float	yt;
	float	zt;

	xt = xyz->xt;
	yt = xyz->yt;
	zt = xyz->zt;
	if (mode % 6 == 2)
	{
		xyz->xt = xt * cos(rad) - yt * sin(rad);
		xyz->yt = xt * sin(rad) + yt * cos(rad);
	}
	else if (mode % 6 == 1)
	{
		xyz->xt = xt * cos(rad) - zt * sin(rad);
		xyz->zt = xt * sin(rad) + zt * cos(rad);
	}
	else if (mode % 6 == 0)
	{
		xyz->yt = yt * cos(rad) - zt * sin(rad);
		xyz->zt = yt * sin(rad) + zt * cos(rad);
	}
}

void		rotate(t_mlx *m, int mode, double rad)
{
	int	r;
	int	c;

	if (mode == 6 || mode == 7 || mode == 8)
		rad *= -1;
	if (mode % 6 == 1)
		m->ang += rad;
	r = -1;
	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
			rotate_help(mode, rad, &(m->map[r][c]));
	}
}

void		stretch(t_mlx *m, int k, double s)
{
	int		r;
	int		c;

	if (k == 37 || k == 44 || k == 41)
		s = 1 - s;
	else
		s = 1 + s;
	r = -1;
	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
		{
			if (k == 37 || k == 43)
				m->map[r][c].xt *= s;
			if (k == 41 || k == 47)
				m->map[r][c].yt *= s;
			if ((k == 39 || k == 44) && m->map[r][c].z)
			{
				m->map[r][c].xt -= abs(m->map[r][c].z) * (s - 1) * sin(m->ang);
				m->map[r][c].zt += abs(m->map[r][c].z) * (s - 1) * cos(m->ang);
			}
		}
	}
}
