/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:37:20 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/01 14:25:48 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ss1;
	char *ss2;

	if (!s1 || !s2)
		return (0);
	if (!(ss1 = ft_strdup(s1)))
		return (0);
	if (!(ss2 = ft_strdup(s2)))
		return (0);
	ft_strcat(ss1, ss2);
	return (ss1);
}
