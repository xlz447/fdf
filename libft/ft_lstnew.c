/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:04:49 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/11 15:04:51 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *out;

	out = (t_list*)malloc(sizeof(*out));
	if (!out)
		return (NULL);
	out->next = NULL;
	if (!content)
	{
		out->content = NULL;
		out->content_size = 0;
		return (out);
	}
	out->content = malloc(content_size);
	if (!out->content)
		return (NULL);
	ft_memcpy(out->content, content, content_size);
	out->content_size = content_size;
	return (out);
}
