/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:53:38 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/11 13:53:40 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1v;
	unsigned char	*s2v;
	size_t			i;

	s1v = (unsigned char*)s1;
	s2v = (unsigned char*)s2;
	i = 0;
	while (n > 0)
	{
		if (s1v[i] != s2v[i])
			return (s1v[i] - s2v[i]);
		i++;
		n--;
	}
	if (i < n)
		return (s1v[i] - s2v[i]);
	else
		return (0);
}
