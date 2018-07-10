/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:29:39 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/13 18:19:54 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0)
		return (dst);
	while (i < len)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
	}
	return (dst);
}
