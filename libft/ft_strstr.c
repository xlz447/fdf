/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:12:07 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 23:12:10 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*found;
	int		val[3];

	val[0] = 0;
	val[1] = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[val[1]] != '\0')
	{
		val[2] = val[1];
		while (needle[val[0]] == haystack[val[2]])
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
	return (0);
}
