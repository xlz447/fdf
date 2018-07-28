/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:57:32 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/11 15:57:33 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst);
	out = temp;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		temp = temp->next;
	}
	return (out);
}
