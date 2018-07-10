/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 08:49:01 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/15 09:52:02 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		index;
	size_t	len;
	char	*str1;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	index = 0;
	if (!(str1 = ft_strnew(len + 1)))
		return (NULL);
	while (len > 0)
	{
		str1[index] = str[len - 1];
		index++;
		len--;
	}
	return (str1);
}
