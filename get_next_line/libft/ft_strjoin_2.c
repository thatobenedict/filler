/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:48:18 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/01 17:26:21 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_2(char const *s1, char const *s2)
{
	int		size;
	char	*new;

	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(sizeof(char) * (size + 1));
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	new[size] = '\0';
	return (new);
}
