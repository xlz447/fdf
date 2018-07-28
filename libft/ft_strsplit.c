/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:40:28 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/10 17:40:30 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(char const *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !c)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			j++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (j);
}

static int		append_output(int data[2], char const *str, char **out, char c)
{
	int x;

	x = 0;
	while (str[data[0]] != c && str[data[0]] != '\0')
	{
		out[data[1]][x] = str[data[0]];
		data[0]++;
		x++;
	}
	out[data[1]][x] = '\0';
	return (data[0]);
}

static void		split_helper(char const *s, int *i, int *k, char c)
{
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	*k = *i;
	while (s[*k] != c && s[*k] != '\0')
		(*k)++;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**out;
	int		word_count;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	if (!(out = (char**)malloc(sizeof(*out) * (word_count + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		split_helper(s, &i, &k, c);
		if (!(out[j] = (char*)malloc(sizeof(**out) * (k - i + 1))))
			return (NULL);
		i = append_output((int[2]){i, j}, s, out, c);
		if (j < word_count)
			j++;
	}
	out[j] = 0;
	return (out);
}
