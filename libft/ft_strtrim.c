/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:25:31 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 16:25:32 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	int		sback;
	int		i;
	char	*out;

	sback = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (space(*s))
		s++;
	i = ft_strlen(s) - 1;
	if (i == -1)
		return (ft_strnew(0));
	while (space(s[i--]))
		sback++;
	out = ft_strnew(ft_strlen(s) - sback);
	if (!out)
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(s) - sback)
	{
		out[i] = s[i];
		i++;
	}
	return (out);
}
