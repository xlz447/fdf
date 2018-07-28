/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:36:00 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/11 18:36:01 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *alst)
{
	size_t	size;
	t_list	*head;

	size = 0;
	head = alst;
	if (!head)
		return (0);
	else
	{
		while (head)
		{
			size++;
			head = head->next;
		}
		return (size);
	}
}
