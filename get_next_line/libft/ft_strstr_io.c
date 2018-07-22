/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_io.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:52:42 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/22 12:30:49 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstr_io(const char *haystack, const char *needle)
{
	int ret;

	ret = 0;
	if (ft_strstr(haystack, needle) != NULL)
		return (ret);
	else
		ret = 1;
	return (ret);
}
