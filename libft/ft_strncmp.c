/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:12:09 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 14:12:10 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1v;
	unsigned char	*s2v;
	size_t			i;

	s1v = (unsigned char*)s1;
	s2v = (unsigned char*)s2;
	i = 0;
	while (s1v[i] != '\0' && n > 0)
	{
		if (s1v[i] != s2v[i])
			return (s1v[i] - s2v[i]);
		i++;
		n--;
	}
	if (s2v[i] != '\0' && n > 0)
		return (s1v[i] - s2v[i]);
	return (0);
}
