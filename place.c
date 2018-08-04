/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:55:12 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/04 15:40:38 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_map(t_filler	*f) 
{
	f->place.count.x = 0;
	f->place.count.y = 0;
	if (f->you.p_id == 'O')
	{
		f->place.piece.x = 'o';
		f->place.piece.y = 'O';
	}
	else
	{
		f->place.piece.x = 'x';
		f->place.piece.y = 'X';
	}
	while (f->place.count.x < f->grid.height)
	{
		f->place.count.y = 0;
		while (f->grid.grid[f->place.count.x][f->place.count.y] != '\0')
		{
			if (f->grid.grid[f->place.count.x][f->place.count.y] == f->place.piece.x ||
					f->grid.grid[f->place.count.x][f->place.count.y] == f->place.piece.y)
				break ;
			f->place.count.y++;
		}
		if (f->grid.grid[f->place.count.x][f->place.count.y] != '\0')
			break ;
		f->place.count.x++;
	}
	ft_putnbr(f->place.count.x);
	ft_putchar(' ');
	ft_putnbr(f->place.count.y);
	ft_putchar('\n'); // delete me
}
