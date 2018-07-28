/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:55:41 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/16 19:55:43 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	appendline(char **data, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*data)[i] != '\n' && (*data)[i] != '\0')
		i++;
	if ((*data)[i] == '\n')
	{
		*line = ft_strsub(*data, 0, i);
		temp = ft_strdup(&((*data)[i + 1]));
		free(*data);
		*data = temp;
		if (!(*data)[0])
			ft_strdel(data);
	}
	else
	{
		*line = ft_strdup(*data);
		ft_strdel(data);
	}
	return (1);
}

static int	dedicated_norm_helper(char **data, char **line, int rd, int fd)
{
	if (rd < 0)
		return (-1);
	else if (rd == 0 && !data[fd])
		return (0);
	else
		return (appendline(&data[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	static char	*data[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	int			rd;
	char		*temp;

	if (fd < 0 || !line)
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if (!data[fd])
			data[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(data[fd], buff);
			free(data[fd]);
			data[fd] = temp;
		}
		if (ft_strchr(data[fd], '\n'))
			break ;
	}
	return (dedicated_norm_helper(data, line, rd, fd));
}
