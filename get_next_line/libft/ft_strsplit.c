/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:23:29 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/15 10:24:50 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_word_count(const char *str, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (str[i] != c)
		j++;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
		{
			j++;
		}
		i++;
	}
	return (j);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s ||
	!(arr = (char **)ft_memalloc(sizeof(char *) * (ft_word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = i;
		while (s[i] != c && i < (size_t)ft_strlen(s))
			i++;
		arr[k] = (char *)ft_strsub(s, j, (i - j));
		k++;
	}
	arr[k] = 0;
	return (arr);
}
