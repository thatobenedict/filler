/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_play_stop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:18:19 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/13 18:58:19 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initial(t_filler *f)
{
	f->turn = 0;
	f->grid.height = 0;
	f->you.height = 0;
	f->you.length = 0;
	f->you.count.x = 0;
	f->you.count.y = 0;
	f->grid.count.x = 0;
	f->grid.count.y = 0;
	f->gnl.fd = 0;
	f->gnl.line = NULL;
}

void	print_play(t_filler *f)
{
	ft_putnbr((f->place.top.x - f->trim.top.y));
	ft_putchar(' ');
	ft_putnbr((f->place.top.y - f->trim.left.y));
	ft_putchar('\n');
}

void	dupe_piece(t_filler *f)
{
	int i;

	i = 0;
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
