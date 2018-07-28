/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:28:03 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/21 11:01:23 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int nb_copy;
	int nb_size;

	nb_size = 1;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n += 2000000000;
		}
		n *= -1;
	}
	nb_copy = n;
	while ((nb_copy /= 10) > 0)
	{
		nb_size *= 10;
	}
	while (nb_size > 0)
	{
		ft_putchar(n / nb_size + '0');
		n %= nb_size;
		nb_size /= 10;
	}
}
