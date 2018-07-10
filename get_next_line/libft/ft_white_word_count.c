/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_white_word_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:42:21 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/15 11:31:59 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_white_word_count(const char *str)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!str || str[i] == '\0')
		return (0);
	if (!ft_whitespace(str[i]))
		j++;
	while (str[i] != '\0')
	{
		if (ft_whitespace(str[i]) && !ft_whitespace(str[i + 1]) && str[i + 1]
				!= '\0')
		{
			j++;
		}
		i++;
	}
	return (j);
}
