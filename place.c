/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:55:12 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/07 09:32:09 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		star_match(t_filler *f, int m_i, int m_j)
{
	int p_i;
	int p_j;
	int overlap;

	p_i 	= 0;
	p_j 	= 0;
	overlap = 0;
	while (p_i < f->trim.new_toke.x && overlap < 2)
	{
		p_j = 0;
		while (p_j < f->trim.new_toke.y && overlap < 2)
		{
			if (f->trim.trim[p_i][p_j] == '*')
			{
				if (f->grid.grid[m_i + p_i][m_j + p_j] != '.')
					overlap++;
			}
			p_j++;
		}
		p_i++;
	}
	return (overlap);
}

void	valid_move(t_filler  *f)
{
	int m_i;
	int m_j;

	m_i =		0;
	m_j =		0;
	while (m_i < (f->grid.height - f->trim.new_toke.x))
	{
		while (m_j < (f->grid.length - f->trim.new_toke.y))
		{
			if ((star_match(f, m_i, m_j)) == 1)
			{	
				if (f->turn == 0)
				{
					ft_putnbr_fd(m_i, 2);
					ft_putchar_fd(' ', 2);
					ft_putnbr_fd(m_j, 2);
					ft_putchar_fd('\n', 2);
				}
			}
			m_j++;
		}
		m_i++;
	}
}

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
