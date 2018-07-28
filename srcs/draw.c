/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:43:11 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/25 22:43:40 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_line(t_mlx *m, t_line l)
{
	int	x[2];
	int	y[2];
	int	e[2];

	x[0] = abs(l.x2 - l.x1);
	x[1] = l.x1 < l.x2 ? 1 : -1;
	y[0] = abs(l.y2 - l.y1);
	y[1] = l.y1 < l.y2 ? 1 : -1;
	e[0] = (x[0] > y[0] ? x[0] : -y[0]) / 2;
	while (l.x1 != l.x2 || l.y1 != l.y2)
	{
		mlx_pixel_put(m->mlx, m->win, l.x1, l.y1, l.color);
		e[1] = e[0];
		e[1] > -x[0] ? e[0] -= y[0] : 1 == 1;
		e[1] > -x[0] ? l.x1 += x[1] : 1 == 1;
		e[1] < y[0] ? e[0] += x[0] : 1 == 1;
		e[1] < y[0] ? l.y1 += y[1] : 1 == 1;
	}
}

static void	draw_col(t_mlx *m, t_line l, int r, int c)
{
	l.x1 = round((int)WIN_W * 0.5 + (m->map[r][c].xt) * m->scale);
	l.y1 = round((int)WIN_H * 0.5 + (m->map[r][c].yt - m->map[r][c].zt)
							* m->scale);
	l.x2 = round((int)WIN_W * 0.5 + (m->map[r][c + 1].xt) * m->scale);
	l.y2 = round((int)WIN_H * 0.5 + (m->map[r][c + 1].yt - m->map[r][c + 1].zt)
							* m->scale);
	draw_line(m, l);
}

static void	draw_row(t_mlx *m, t_line l, int r, int c)
{
	l.x1 = round((int)WIN_W * 0.5 + (m->map[r][c].xt) * m->scale);
	l.y1 = round((int)WIN_H * 0.5 + (m->map[r][c].yt - m->map[r][c].zt)
							* m->scale);
	l.x2 = round((int)WIN_W * 0.5 + (m->map[r + 1][c].xt) * m->scale);
	l.y2 = round((int)WIN_H * 0.5 + (m->map[r + 1][c].yt - m->map[r + 1][c].zt)
							* m->scale);
	draw_line(m, l);
}

void		draw(t_mlx *m)
{
	int			r;
	int			c;
	t_line		l;

	l.color = 0xffffff;
	r = -1;
	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
		{
			if (c + 1 < m->col)
				draw_col(m, l, r, c);
			if (r + 1 < m->row)
				draw_row(m, l, r, c);
		}
	}
}
