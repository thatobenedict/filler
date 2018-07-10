/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:20:28 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/14 09:43:24 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*snew;
	int		i;

	i = 0;
	if (s)
	{
		if ((snew = ft_strdup(s)))
		{
			if (snew[i] != '\0')
			{
				while (snew[i] != '\0')
				{
					snew[i] = f(snew[i]);
					i++;
				}
				return (snew);
			}
		}
	}
	return (0);
}
