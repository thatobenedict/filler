/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:11:37 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/14 06:45:53 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	top(t_filler *f)
{
	f->trim.top.x = 0;
	f->trim.top.y = 0;
	while (f->trim.top.x < f->you.height)
	{
		if (ft_contain_char(f->you.toke[f->trim.top.x], '*') == 0)
		{
			f->trim.top.x++;
			f->trim.top.y++;
		}
		else
			break ;
	}
}

void	bottom(t_filler *f)
{
	f->trim.bottom.x = f->you.height - 1;
	f->trim.bottom.y = 0;
	while (f->trim.bottom.x > 0)
	{
		if (ft_contain_char(f->you.toke[f->trim.bottom.x], '*') != 1)
		{
			f->trim.bottom.x--;
			f->trim.bottom.y++;
		}
		else
			break ;
	}
}

void	left(t_filler *f)
{
	f->trim.left.x = 0;
	f->trim.left.y = 0;
	while (f->trim.left.x < f->you.length)
	{
		if (ft_contain_char_col(f->you.toke, f->trim.left.x, f->you.height, '*')
				== 1)
			break ;
		else
		{
			f->trim.left.x++;
			f->trim.left.y++;
		}
	}
}

void	right(t_filler *f)
{
	f->trim.right.x = f->you.length - 1;
	f->trim.right.y = 0;
	while (f->trim.right.x > 0)
	{
		if (ft_contain_char_col(f->you.toke, f->trim.right.x, f->you.height,
					'*') == 1)
			break ;
		else
		{
			f->trim.right.x--;
			f->trim.right.y++;
		}
	}
}

void	trim_piece(t_filler *f)
{
	int		i;
	int		j;

	if (f->turn > 0)
		free(f->trim.trim);
	i = 0;
	j = f->trim.top.y;
	if (f->trim.bottom.y == 0 && f->trim.top.y == 0 &&
			f->trim.left.y == 0 && f->trim.right.y == 0)
		dupe_piece(f);
	else
	{
		f->trim.new_toke.x = f->you.height - (f->trim.bottom.y + f->trim.top.y);
		f->trim.new_toke.y = f->you.length - (f->trim.right.y + f->trim.left.y);
		f->trim.trim = (char **)ft_memalloc(sizeof(char *) * (f->trim.new_toke.x
					+ 1));
		while (i < f->trim.new_toke.x)
		{
			f->trim.trim[i] = (char *)ft_strndup(f->you.toke[j]
					+ f->trim.left.y, f->trim.new_toke.y);
			i++;
			j++;
		}
		f->trim.trim[f->trim.new_toke.x] = 0;
	}
}
