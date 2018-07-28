/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:22:58 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 14:22:59 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	j;

	if (!s)
		return (NULL);
	out = ft_strnew(len);
	if (!out)
		return (NULL);
	j = 0;
	out[len] = '\0';
	while (len > 0)
	{
		out[j++] = s[start++];
		len--;
	}
	return (out);
}
