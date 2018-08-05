/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:11:37 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/05 18:24:04 by tbenedic         ###   ########.fr       */
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
		if (ft_contain_char_col(f->you.toke, f->trim.left.x, '*') != 1)
		{
			f->trim.left.x++;
			f->trim.left.y++;
		}
		else
			break ;
	}
}

void	right(t_filler	*f)
{
	f->trim.right.x = f->you.length - 1;
	f->trim.right.y = 0;

	while (f->trim.right.x > 0)
	{
		if (ft_contain_char_col(f->you.toke, f->trim.right.x, '*') != 1)
		{
			f->trim.right.x--;
			f->trim.right.y++;
		}
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
	if (f->turn > 1)
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
	}
	else
	{
		len  = f->trim.bottom.y - f->trim.top.y + 1;
		high  = f->trim.right.y - f->trim.left.y + 1;
		f->trim.trim = (char **)ft_memalloc(sizeof(char *) * (high + 1));
		while (i <= high)
		{
			f->trim.trim[i] = (char *)ft_strndup(f->you.toke[f->trim.top.y]
					+ f->trim.left.y, f->you.length - f->trim.right.y);
			i++;
		}
		f->you.toke[high + 1] = 0;
	}

	///////DELETE WHEN DONE///////
	if (f->turn >= 2)
	{
		fd = open ("gnl", O_WRONLY, 0777);
		ft_putstr_fd("height: ", fd);
		ft_putnbr_fd(f->you.height, fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("length: ", fd);
		ft_putnbr_fd(f->you.length, fd);
		ft_putchar_fd('\n', fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("top trim: ", fd);
		ft_putnbr_fd(f->trim.top.y, fd);
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
		close (fd);
	}
	///////DELETE WHEN DONE///////

}
