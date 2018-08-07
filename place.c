/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:55:12 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/07 18:27:11 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> ///////DELETEME

int		star_match(t_filler *f, int m_i, int m_j)
{
	int p_i;
	int p_j;
	int overlap;

	p_i 	= 0;
	p_j 	= 0;
	overlap = 0;
	while (p_i < f->trim.new_toke.x )// && overlap < 2)
	{
		p_j = 0;
		while (p_j < f->trim.new_toke.y )//&& overlap < 2)
		{
			if (f->trim.trim[p_i][p_j] == '*')
			{
				if (f->grid.grid[m_i + p_i][m_j + p_j] == f->you.p_id ||
						f->grid.grid[m_i + p_i][m_j + p_j] == f->you.p_id + 32)
					overlap++;
				else if (f->grid.grid[m_i + p_i][m_j + p_j] == f->opp.p_id ||
						f->grid.grid[m_i + p_i][m_j + p_j] == f->opp.p_id + 32)
					return (0);
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
	ft_putstr_fd("Original Piece\n", 2);
	ft_puttab_fd(f->you.toke, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Trimmed Piece\n", 2);
	ft_puttab_fd(f->trim.trim, 2);

	while (m_i < (f->grid.height - f->trim.new_toke.x))
	{
		m_j = 0;
		while (m_j < (f->grid.length - f->trim.new_toke.y))
		{
			if ((star_match(f, m_i, m_j)) == 1)
			{	
				if (1)
				{
					ft_putnbr((m_j - f->trim.top.y));
					ft_putchar(' ');
					ft_putnbr((m_i - f->trim.left.y));
					ft_putchar('\n'); // delete me
					fprintf(stderr, "START\n(%d, %d)\n", m_j, m_i);
					fprintf(stderr, "OFFSET\n(%d, %d)\n",f->trim.top.y, f->trim.left.y);

					fprintf(stderr, "bot&left\n(%d, %d)\n",f->trim.bottom.y, f->trim.right.y);
					//				fprintf(stderr, "%d %d\n", m_i - f->trim.top.y, m_j - f->trim.left.y);
					return ;
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
