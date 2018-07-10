/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:21:08 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/14 16:48:45 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	if ((fresh = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	ft_bzero(fresh, size + 1);
	return (fresh);
}
