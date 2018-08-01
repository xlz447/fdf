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

static void	print_instructions(t_mlx *m)
{
	mlx_string_put(m->mlx, m->win, 0, 0, 0xff0000, "Instructions: ");
	mlx_string_put(m->mlx, m->win, 0, 20, 0xff0000, "Zoom in/out: mouse wheel");
	mlx_string_put(m->mlx, m->win, 0, 40, 0xff0000,
		"Reposition: key <up down left right> arrows");
	mlx_string_put(m->mlx, m->win, 0, 60, 0xff0000, "Stretch x: key <, l>");
	mlx_string_put(m->mlx, m->win, 0, 80, 0xff0000, "Stretch y: key <. ;>");
	mlx_string_put(m->mlx, m->win, 0, 100, 0xff0000,
		"Change altitude: key </ '>");
	mlx_string_put(m->mlx, m->win, 0, 120, 0xff0000, "Rotate x: key <a z>");
	mlx_string_put(m->mlx, m->win, 0, 140, 0xff0000, "Rotate y: key <s x>");
	mlx_string_put(m->mlx, m->win, 0, 160, 0xff0000, "Rotate z: key <d c>");
	mlx_string_put(m->mlx, m->win, 0, 180, 0xff0000, "Reset: key <r>");
	mlx_string_put(m->mlx, m->win, 0, 200, 0xff0000, "Draw line: mouse click");
	mlx_string_put(m->mlx, m->win, 0, 220, 0xff0000,
		"Print Instructions: key <i>");
}

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
		setup(m);
	if (k == 34)
		print_instructions(m);
	draw(m);
	return (0);
}

static void	check_append(int fd, t_mlx *m, char **temp, char *filename)
{
	char	*line;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	ft_free_2d((void**)temp);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		temp = ft_strsplit(line, ' ');
		free(line);
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
		ft_free_2d((void**)temp);
	}
	close(fd);
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
	get_next_line(fd, &line);
	temp = ft_strsplit(line, ' ');
	free(line);
	while (temp[count])
		count++;
	m->col = count;
	count = 1;
	while ((get_next_line(fd, &line)) > 0 && ++count)
		free(line);
	m->row = count;
	m->map = (t_xyz **)ft_memalloc(m->row * sizeof(t_xyz));
	count = -1;
	while (++count < m->row)
		m->map[count] = (t_xyz *)ft_memalloc(m->col * sizeof(t_xyz));
	close(fd);
	check_append(fd, m, temp, filename);
	setup(m);
}

int			main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 3 && argc != 2)
		ft_errorexit("usage: ./fdf <filename> [0x0x87ceeb]");
	if (argc == 3)
	{
		m.color = (unsigned int)ft_atoi(argv[2]);
		if (m.color == 0)
			m.color = 0x87ceeb;
	}
	else
		m.color = 0x87ceeb;
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "fdf");
	read_file(&m, argv[1]);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_mouse_hook(m.win, mouse_handler, &m);
	print_instructions(&m);
	draw(&m);
	mlx_loop(m.mlx);
	return (0);
}
