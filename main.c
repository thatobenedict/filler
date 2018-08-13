/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/13 18:51:07 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_player(t_filler *f)
{
	get_next_line(f->gnl.fd, &(f->gnl.line));
	f->you.p_id = (f->gnl.line[10] == '1') ? 'O' : 'X';
	f->opp.p_id = (f->gnl.line[10] == '1') ? 'X' : 'O';
}

void		get_map(t_filler *f)
{
	int i;

	i = 0;
	get_next_line(f->gnl.fd, &(f->gnl.line));
	if (f->turn == 0)
	{
		f->grid.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
		f->grid.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
		f->grid.grid =
			(char **)ft_memalloc(sizeof(char *) * f->grid.height + 1);
	}
	get_next_line(f->gnl.fd, &(f->gnl.line));
	while (i < (f->grid.height))
	{
		get_next_line(f->gnl.fd, &(f->gnl.line));
		f->grid.grid[i] = (char *)ft_strdup(f->gnl.line + 4);
		i++;
	}
	f->grid.grid[f->grid.height] = 0;
}

void		get_piece(t_filler *f)
{
	int i;

	i = 0;
	get_next_line(f->gnl.fd, &(f->gnl.line));
	if (f->turn > 0)
	{
		free(f->you.toke);
		f->you.length = 0;
		f->you.height = 0;
	}
	f->you.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
	f->you.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
	f->you.toke = (char **)ft_memalloc(sizeof(char *) * f->you.height + 1);
	while (i < f->you.height)
	{
		get_next_line(f->gnl.fd, &(f->gnl.line));
		f->you.toke[i] = (char *)ft_strdup(f->gnl.line);
		i++;
	}
	f->you.toke[f->you.height] = 0;
}

int			main(void)
{
	t_filler	*f;

	f = ft_memalloc(sizeof(t_filler));
	ft_initial(f);
	get_player(f);
	while (1)
	{
		get_map(f);
		get_piece(f);
		top(f);
		bottom(f);
		left(f);
		right(f);
		trim_piece(f);
		valid_move(f);
		if (f->turn == -1)
			break ;
		print_play(f);
		f->turn += 1;
	}
	ft_putendl("0 0");
	return (0);
}
