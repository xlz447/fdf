/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 21:47:23 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 21:47:24 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_helper(int x, char *out)
{
	if (x)
		out[0] = '-';
}

char			*ft_itoa(int n)
{
	int			val[3];
	char		*out;

	val[2] = 0;
	val[1] = 1;
	if (n < 0 && val[1]++)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n *= -1;
		val[2] = 1;
	}
	val[0] = n;
	while ((val[0] /= 10) > 0)
		val[1]++;
	if (!(out = (char*)malloc(sizeof(*out) * (val[1] + 1))))
		return (NULL);
	out[val[1]] = '\0';
	while (val[1]-- >= 1)
	{
		out[val[1]] = (n % 10) + '0';
		n /= 10;
	}
	itoa_helper(val[2], out);
	return (out);
}
