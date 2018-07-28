/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:02:31 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 14:02:34 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1v;
	unsigned char	*s2v;
	size_t			i;

	s1v = (unsigned char*)s1;
	s2v = (unsigned char*)s2;
	i = 0;
	while (s1v[i] != '\0')
	{
		if (s1v[i] != s2v[i])
			return (s1v[i] - s2v[i]);
		i++;
	}
	if (s2v[i] != '\0')
		return (s1v[i] - s2v[i]);
	return (0);
}
