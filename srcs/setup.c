/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:30:08 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/25 22:30:11 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_scale(t_mlx *m)
{
	int		r;
	int		c;
	float	a;
	float	b;

	r = -1;
	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
		{
			if (m->map[r][c].xt > m->max_x)
				m->max_x = m->map[r][c].xt;
			if (m->map[r][c].xt < m->min_x)
				m->min_x = m->map[r][c].xt;
			if (m->map[r][c].yt - m->map[r][c].zt > m->max_y)
				m->max_y = m->map[r][c].yt - m->map[r][c].zt;
			if (m->map[r][c].yt - m->map[r][c].zt < m->min_y)
				m->min_y = m->map[r][c].yt - m->map[r][c].zt;
		}
	}
	a = (float)WIN_W * 0.8 / (m->max_x - m->min_x);
	b = (float)WIN_H * 0.8 / (m->max_y - m->min_y);
	m->scale = (a < b) ? a : b;
}

void		calibrate(t_mlx *m)
{
	int		r;
	int		c;
	float	s[3];
	float	sc;

	if ((float)WIN_W / (m->col - 1) < (float)WIN_H / (m->row - 1))
		sc = (float)WIN_W / (m->col - 1);
	else
		sc = (float)WIN_H / (m->row - 1);
	r = -1;
	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
		{
			s[0] = sc * (m->map[r][c].x - m->map[m->row / 2][m->col / 2].x);
			s[1] = sc * (m->map[r][c].y - m->map[m->row / 2][m->col / 2].y);
			s[2] = WIN_H * 0.1 / (m->max_h - m->min_h) * m->map[r][c].z;
			m->map[r][c].xt = s[0] * cos(m->ang) - (s[1] * sin(m->ang) +
					s[2] * cos(m->ang)) * sin(m->ang);
			m->map[r][c].yt = s[1] * cos(m->ang) - s[2] * sin(m->ang);
			m->map[r][c].zt = s[0] * sin(m->ang) + (s[1] * sin(m->ang) +
					s[2] * cos(m->ang)) * cos(m->ang);
		}
	}
}

void		mouse_helper(t_mlx *m, int button)
{
	mlx_clear_window(m->mlx, m->win);
	scale(m, button, 1.10);
	draw(m);
}

int			mouse_handler(int button, int x, int y, t_mlx *m)
{
	static int		put;
	static int		oldx;
	static int		oldy;
	static t_line	l;

	l.color = 0x00ffff;
	if (button == 1)
	{
		if (put)
		{
			l.x2 = x;
			l.y2 = y;
			draw_line(m, l);
			put = 0;
		}
		else
		{
			l.x1 = x;
			l.y1 = y;
			put = 1;
		}
	}
	else if (button == 4 || button == 5)
		mouse_helper(m, button);
	return (0);
}

void		setup(t_mlx *m)
{
	int c;
	int r;

	m->scale = 0;
	m->ang = PI / 30;
	m->max_h = INT_MIN;
	m->min_h = INT_MAX;
	m->max_x = INT_MIN;
	m->min_x = INT_MAX;
	m->max_y = INT_MIN;
	m->min_y = INT_MAX;
	r = -1;
	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
		{
			if (m->map[r][c].z > m->max_h)
				m->max_h = m->map[r][c].z;
			if (m->map[r][c].z < m->min_h)
				m->min_h = m->map[r][c].z;
		}
	}
	calibrate(m);
	get_scale(m);
}
