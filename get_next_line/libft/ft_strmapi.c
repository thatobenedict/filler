/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:27:09 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/14 09:42:43 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*snew;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if ((snew = ft_strdup(s)))
		{
			if (snew[i] != '\0')
			{
				while (snew[i] != '\0')
				{
					snew[i] = f(i, snew[i]);
					i++;
				}
				return (snew);
			}
		}
	}
	return (0);
}
