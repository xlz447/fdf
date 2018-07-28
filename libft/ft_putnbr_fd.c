/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:11:00 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 16:11:17 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int nb_copy;
	int nb_size;

	nb_size = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
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
		ft_putchar_fd(n / nb_size + '0', fd);
		n %= nb_size;
		nb_size /= 10;
	}
}
