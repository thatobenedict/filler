/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:11:37 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/07 16:15:56 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	top(t_filler	*f)
{
	f->trim.top.x = 0;
	f->trim.top.y = 0;

	while (f->trim.top.x < f->you.height)
	{
		if (ft_contain_char(f->you.toke[f->trim.top.x], '*') != 1)
		{
			f->trim.top.x++;
			f->trim.top.y++;
		}
		else
			break ;
	}
}
void	bottom(t_filler	*f)
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

void	left(t_filler	*f)
{
	f->trim.left.x = 0;
	f->trim.left.y = 0;

	while (f->trim.left.x < f->you.length)
	{
		if (ft_contain_char_col(f->you.toke, f->trim.left.x,f->you.height, '*') == 1)
			break ;
		else
		{
			f->trim.left.x++;
			f->trim.left.y++;
		}

	}
}

void	right(t_filler	*f)
{
	f->trim.right.x = f->you.length - 1;
	f->trim.right.y = 0;

	while (f->trim.right.x > 0)
	{
		if (ft_contain_char_col(f->you.toke, f->trim.right.x,f->you.height, '*') == 1)
			break ;	
		else
		{
			f->trim.right.x--;
			f->trim.right.y++;
		}

	}
}

void            trim_piece(t_filler *f)
{
	int		i;
	top(f);
	bottom(f);
	left(f);
	right(f);
	if (f->turn > 0)
		free (f->trim.trim);
	i = 0;
	if (f->trim.bottom.y == 0 && f->trim.top.y == 0 && 
			f->trim.left.y == 0 && f->trim.right.y == 0)
	{
		f->trim.trim = (char **)ft_memalloc(sizeof(char *) * f->you.height + 1);
		while (i < f->you.height)
		{
			f->trim.trim[i] = (char *)ft_strdup(f->you.toke[i]);
			i++;
		}
		f->trim.trim[f->you.height] = 0;
		f->trim.new_toke.x = f->you.height;
		f->trim.new_toke.y = f->you.length;
	}
	else
	{
		f->trim.new_toke.x = f->you.height - (f->trim.bottom.y + f->trim.top.y);
		f->trim.new_toke.y = f->you.length - (f->trim.right.y + f->trim.left.y);
		f->trim.trim = (char **)ft_memalloc(sizeof(char *) * (f->trim.new_toke.x + 1));
		while (i < f->trim.new_toke.x)
		{
			f->trim.trim[i] = (char *)ft_strndup(f->you.toke[f->trim.top.y]
					+ f->trim.left.y, f->you.length - f->trim.right.y);
			i++;
			f->trim.top.y++;
		}
		f->trim.trim[f->trim.new_toke.x] = 0;
	}	

	/*	///////DELETE WHEN DONE///////
		if (f->turn == 0)
		{
		fd = 2;
		ft_putstr_fd("height: ", fd);
		ft_putnbr_fd(f->you.height, fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("length: ", fd);
		ft_putnbr_fd(f->you.length, fd);
		ft_putchar_fd('\n', fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("top trim: ", fd);
		ft_putnbr_fd(f->trim.top.x, fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("bottom trim: ", fd);
		ft_putnbr_fd(f->trim.bottom.y, fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("left trim: ", fd);
		ft_putnbr_fd(f->trim.left.y, fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("right trim: ", fd);
		ft_putnbr_fd(f->trim.right.y, fd);
		ft_putchar_fd('\n', fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("Original Piece\n", fd);
		ft_puttab_fd(f->you.toke, fd);		
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("Trimmed Piece\n", fd);
		ft_puttab_fd(f->trim.trim, fd);		

		}	///////DELETE WHEN DONE///////
		*/}
