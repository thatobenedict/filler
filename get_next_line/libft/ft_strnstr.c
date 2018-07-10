/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:42:50 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/14 15:49:25 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len - k + 1 && len >= k)
	{
		j = 0;
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (j == k)
				return ((char *)haystack + (i - j));
		}
		i = i - j + 1;
	}
	return (NULL);
}
