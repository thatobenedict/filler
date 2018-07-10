/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:16:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/01 17:25:11 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char *ss1;
	char *ss2;

	if (!s1 || !s2)
		return (0);
	if (!(ss1 = ft_strdup(s1)))
		return (0);
	if (!(ss2 = ft_strndup(s2, n)))
		return (0);
	ft_strcat(ss1, ss2);
	return (ss1);
}
