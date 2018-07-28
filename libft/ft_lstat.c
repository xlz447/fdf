/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:45:19 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/11 18:45:21 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *alst, unsigned int nbr)
{
	t_list			*temp;
	unsigned int	i;

	i = 0;
	temp = alst;
	if (!alst)
		return (NULL);
	while (temp && i < nbr)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}
