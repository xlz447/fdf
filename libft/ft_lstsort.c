/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:43:29 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/11 18:43:31 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **alst, int (*cmp)())
{
	t_list	*temp;
	t_list	*head;
	void	*data;

	head = *alst;
	while (head)
	{
		temp = *alst;
		while (temp->next)
		{
			if ((*cmp)(temp->content, temp->next->content) > 0)
			{
				data = temp->content;
				temp->content = temp->next->content;
				temp->next->content = data;
			}
			temp = temp->next;
		}
		head = head->next;
	}
}
