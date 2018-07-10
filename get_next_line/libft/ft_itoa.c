/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:01:12 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/14 14:56:13 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_int(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*num;

	i = ft_count_int(n);
	j = 0;
	if (!(num = ft_strnew(i)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		num[0] = '-';
		j = 1;
		n = -n;
	}
	while (i - 1 >= j)
	{
		num[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (num);
}
