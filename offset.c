/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:11:37 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/04 17:19:52 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	top(t_filler	*f)
{
	f->trim.top.x = 0;

	while (f->trim.top.x < f->you.height)
	{
		if (ft_contain_char(f->you.toke[f->trim.top.x], '*') == 0)
			f->trim.top.x++;
		else
			break ;
	}
}

void	bottom(t_filler	*f)
{
	f->trim.bottom.x = f->you.height - 1;

	while (f->trim.bottom.x >= 0)
	{
		if (ft_contain_char(f->you.toke[f->trim.bottom.x], '*') == 0)
			f->trim.bottom.x--;
		else
			break ;
	}
}

void	left(t_filler	*f)
{
	f->trim.left.x = 0;

	while (f->trim.left.x < f->you.length)
	{
		if (ft_contain_char_col(f->you.toke, f->trim.left.x, '*') == 0)
			f->trim.left.x++;
		else
			break ;
	}
}

void	right(t_filler	*f)
{
	f->trim.right.x = f->you.length - 1;

	while (f->trim.right.x >= 0)
	{
		if (ft_contain_char_col(f->you.toke, f->trim.right.x, '*') == 0)
			f->trim.right.x--;
		else
			break ;
	}
}

void            trim_piece(t_filler *f)
{
	int		len;
	int		high;
	int		i;

	top(f);
	bottom(f);
	left(f);
	right(f);
	i = 0;
	len  = f->trim.bottom.x - f->trim.top.x + 1;
	high  = f->trim.right.x - f->trim.left.x + 1;
	if (f->turn > 1)
		free (f->trim.trim);
	f->trim.trim = (char **)ft_memalloc(sizeof(char *) * (high + 1));
	while (i <= high)
	{
		f->trim.trim[i] = (char *)ft_strndup(f->you.toke[f->trim.top.x]
				+ f->trim.left.x, f->you.length - f->trim.right.x);
		i++;
	}
	f->you.toke[high + 1] = 0;

	int n = 0;
	int m = 0;
	while (n < high)
	{

			fprintf("%s",f->trim.trim[n]);
	}


}
