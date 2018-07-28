/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:17:26 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/25 22:17:31 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			key_handler(int k, t_mlx *m)
{
	if (k == 53)
		exit(0);
	mlx_clear_window(m->mlx, m->win);
	if (k == 0 || k == 1 || k == 2 || k == 6 || k == 7 || k == 8)
		rotate(m, k, PI / 12);
	if (k == 123 || k == 124 || k == 125 || k == 126)
		shift(m, k, (int)WIN_W * 0.2);
	if (k == 37 || k == 43 || k == 41 || k == 47 || k == 39 || k == 44)
		stretch(m, k, 0.1);
	if (k == 15)
		calibrate(m);
	draw(m);
	return (0);
}

static void	check_append(int fd, t_mlx *m)
{
	char	*line;
	char	**temp;
	int		i;
	int		j;

	j = 0;
	while (get_next_line(fd, &line))
	{
		temp = ft_strsplit(line, ' ');
		i = -1;
		while (temp[++i])
		{
			m->map[j][i].x = i;
			m->map[j][i].y = j;
			m->map[j][i].z = ft_atoi(temp[i]);
		}
		if (i != m->col)
			ft_errorexit("Error: inconsistent length");
		j++;
	}
}

static void	read_file(t_mlx *m, char *filename)
{
	int		fd;
	int		count;
	char	*line;
	char	**temp;

	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_errorexit("Error: file not found");
	count = 0;
	while ((get_next_line(fd, &line)) > 0)
		count++;
	m->row = count;
	temp = ft_strsplit(line, ' ');
	count = 0;
	while (temp[count])
		count++;
	m->col = count;
	m->map = (t_xyz **)ft_memalloc(m->row * sizeof(t_xyz));
	count = -1;
	while (++count < m->row)
		m->map[count] = (t_xyz *)ft_memalloc(m->col * sizeof(t_xyz));
	close(fd);
	fd = open(filename, O_RDONLY);
	check_append(fd, m);
	setup(m);
	close(fd);
}

int			main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 2)
		ft_errorexit("usage: ./fdf <filename>");
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "fdf");
	read_file(&m, argv[1]);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_mouse_hook(m.win, mouse_handler, &m);
	draw(&m);
	mlx_loop(m.mlx);
	return (0);
}
