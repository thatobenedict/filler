/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:27:55 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/14 16:52:40 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	int				k;
	char			*sub;

	if (!s)
		return (0);
	i = 0;
	j = start;
	k = j + (int)len;
	if (!(sub = (ft_strnew(len))))
		return (0);
	while (s && j < k)
	{
		sub[i] = s[j];
		i++;
		j++;
	}
	sub[len] = '\0';
	return (sub);
}
