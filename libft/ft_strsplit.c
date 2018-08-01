/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:40:28 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 17:40:30 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strword(char const *s, char c)
{
	int n;

	n = 0;
	if (!s)
		return (n);
	while (*s)
		if (*s == c)
			++s;
		else if (++n && *++s)
			while (*s != c)
				++s;
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	int			nw;
	char const	*chr;
	char		**r;
	char		**ptr;

	nw = ft_strword(s, c);
	if (!(r = malloc((nw + 1) * sizeof(char *))))
		return (NULL);
	ptr = r;
	while (s && *s)
		if (*s == c)
			++s;
		else
		{
			chr = s;
			while (*chr && *chr != c)
				++chr;
			nw = chr - s;
			if (!(*ptr = malloc((nw + 1) * sizeof(char))))
				return (NULL);
			ft_strncpy(*ptr++, s, nw)[nw] = '\0';
			s += nw;
		}
	*ptr = NULL;
	return (r);
}
