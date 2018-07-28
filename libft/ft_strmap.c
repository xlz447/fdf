/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:54:39 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/09 21:54:40 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	out = ft_strnew(ft_strlen(s));
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = (*f)(s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
