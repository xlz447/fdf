/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:19:06 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 23:19:15 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*found;
	size_t	val[3];

	val[0] = 0;
	val[1] = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[val[1]] != '\0' && val[1] < len)
	{
		val[2] = val[1];
		while (needle[val[0]] == haystack[val[2]] && val[0] + val[1] < len)
		{
			if (needle[val[0] + 1] == '\0')
			{
				found = (char *)&haystack[val[1]];
				return (found);
			}
			val[0]++;
			val[2]++;
		}
		val[0] = 0;
		val[1]++;
	}
	return (NULL);
}
