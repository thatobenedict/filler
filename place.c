/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:55:12 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/12 18:27:33 by tbenedic         ###   ########.fr       */
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
					overlap++; // rather return int * and include the score
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

int		ft_abs(int a, int b)
{
	if (a > b)
		return (a - b);
	else if (b > a)
		return (b - a);
	else if (a == b)
		return (0);
}

int		score_gen(int x, int y, t_filler f)
{
	if (f->grid.height == 14)
	{

	}
	else if (f->grid.height == 23)
	{
	}
	else if (f->grid.height == 99)
	{
	}

}

void	valid_move(t_filler  *f)
{
	int m_i;
	int m_j;
	int curr_score;
	int top_score;
	m_i =		0;
	m_j =		0;
	curr_score = 0;
	top_score = 0;
	while (m_i < (f->grid.height - f->trim.new_toke.x))
	{
		m_j = 0;
		while (m_j < (f->grid.length - f->trim.new_toke.y))
		{
			if ((star_match(f, m_i, m_j)) == 1)
			{
				curr_score = rand (); // this is where the maps must be called
				if (top_score <= curr_score)
				{
					top_score = curr_score;
					f->place.top.x = m_i;
					f->place.top.y = m_j;
				}
			}
			m_j++;
		}
		m_i++;
	}
	if (top_score == 0) // you need a better exit condition
		f->turn = -1;
	return ;
}

void	print_play(t_filler *f)
{
	if (f->turn == -1)
		ft_putendl("0 0");
	else
	{
		ft_putnbr((f->place.top.x - f->trim.top.y));
		ft_putchar(' ');
		ft_putnbr((f->place.top.y - f->trim.left.y));
		ft_putchar('\n');
	}
}
