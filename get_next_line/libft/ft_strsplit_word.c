/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:41:24 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/18 17:59:13 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
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
*/
char				*ft_strsplit_word(char const *s, char c, size_t num)
{
	char		*arr;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s)
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
		if (k + 1 == num)
			arr = (char *)ft_strsub(s, j, (i - j));
		k++;
	}
	return (arr);
}
