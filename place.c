/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:55:12 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/12 16:53:47 by tbenedic         ###   ########.fr       */
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
	while (p_i < f->trim.new_toke.x)
	{
		p_j = 0;
		while (p_j < f->trim.new_toke.y)
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
	while (m_i < (f->grid.height - f->trim.new_toke.x))
	{
		m_j = 0;
		while (m_j < (f->grid.length - f->trim.new_toke.y))
		{
			if ((star_match(f, m_i, m_j)) == 1)
			{	
				ft_putnbr((m_i - f->trim.top.y));
				ft_putchar(' ');
				ft_putnbr((m_j - f->trim.left.y));
				ft_putchar('\n');
				return ;
			}
			m_j++;
		}
		m_i++;
	}
	f->turn = -1;
	return ;
}
