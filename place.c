/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:55:12 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/14 10:18:18 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		star_match(t_filler *f, int m_i, int m_j)
{
	int p_i;
	int p_j;
	int overlap;

	p_i = -1;
	p_j = -1;
	overlap = 0;
	while (++p_i < f->trim.new_toke.x)
	{
		p_j = -1;
		while (++p_j < f->trim.new_toke.y)
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
		}
	}
	return (overlap);
}

int		ft_abs(int a, int b)
{
	if (a > b)
		return (a - b);
	else if (b > a)
		return (b - a);
	return (0);
}

int		score_gen(int x, int y, t_filler *f)
{
	int score;

	score = 0;
	if (f->grid.height == 15)
	{
		if (f->you.p_id == 'X')
			score = 200 - (ft_abs(x, 7) + ft_abs(y, 0));
		else
		{
			if (f->turn < 3)
				score = 200 - (ft_abs(x, 3) + ft_abs(y, 0));
			else
				score = 200 - (ft_abs(x, 7) + ft_abs(y, 16));
		}
	}
	else if (f->grid.height == 24 && f->you.p_id == 'O')
		score = 200 - (ft_abs(x, 12) + ft_abs(y, 20));
	else if (f->grid.height == 24 && f->you.p_id == 'X')
	{
		if (f->turn > 35)
			score = (ft_abs(x, 12) + ft_abs(y, 20));
		else if (f->turn % 2 == 0)
			score = 1000 - (ft_abs(x, 19) + ft_abs(y, 0));
		else
			score = 1000 - (ft_abs(y, 32) + ft_abs(x, 0));
	}
	else if (f->grid.height == 100)
		score = 200 - (ft_abs(x, 50) + ft_abs(y, 49));
	return (score);
}

void	valid_move(t_filler *f)
{
	int m_i;
	int m_j;
	int top_score;

	m_i = -1;
	m_j = -1;
	top_score = 0;
	while (++m_i < (f->grid.height - f->trim.new_toke.x))
	{
		m_j = -1;
		while (++m_j < (f->grid.length - f->trim.new_toke.y))
		{
			if ((star_match(f, m_i, m_j)) == 1)
			{
				if (top_score < score_gen(m_i, m_j, f))
				{
					top_score = score_gen(m_i, m_j, f);
					f->place.top.x = m_i;
					f->place.top.y = m_j;
				}
			}
		}
	}
	if (top_score == 0)
		f->turn = -1;
}
