/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:46:36 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/09 20:46:38 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*out;
	size_t	i;

	i = 0;
	out = (char*)malloc(sizeof(*out) * size + 1);
	if (!out)
		return (NULL);
	while (i <= size)
		out[i++] = '\0';
	return (out);
}
