/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:55:12 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/23 16:54:14 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cord		place_map(char   **grid, int id)
{
	t_cord  count;
	int		x;
	int		y;
	char	c;
	char	d;

	x = 0;
	y = 0;
	if (id == 0)
	{
		c = 'o';
		d = 'O';
	}
	else
	{
		c = 'x';
		d = 'X';
	}

	while (grid[x] != 0)
	{
		y = 0;
		while (grid[x][y] != '\0')
		{
			if (grid[x][y] == c || grid[x][y] == d)
				break ;
			y++;
		}
		if (grid[x][y] == c || grid[x][y] == d)
			break ;
		x++;
	}
	count.x = x;
	count.y = y;
	ft_putnbr(count.x);
	ft_putchar(' ');
	ft_putnbr(count.y);
	ft_putchar('\n');
	return (count);
}
