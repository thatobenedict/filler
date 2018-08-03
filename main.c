/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/03 18:14:43 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	top_left(t_filler	*f);
void	place_map(t_filler	*f);

void		get_player(t_filler		*f)
{
	f->you.p_id	= (f->gnl.line[10] == '1') ? 'O' : 'X';
	f->opp.p_id	= (f->gnl.line[10] == '1') ? 'X' : 'O';
}

void		get_map(t_filler *f)
{
	if (f->turn == 0)
	{
		f->grid.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
		f->grid.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
		f->grid.grid = (char **)ft_memalloc(sizeof(char *) * f->grid.height + 1);
		f->gnl.strbuf = get_next_line(f->gnl.fd, &(f->gnl.line));
	}
	else
		f->gnl.strbuf = get_next_line(f->gnl.fd, &(f->gnl.line));
	while (f->grid.count.y <= (f->grid.height) &&
			(f->gnl.strbuf = get_next_line(f->gnl.fd, &(f->gnl.line))) == 1)
	{
		f->grid.grid[f->grid.count.y] = (char *)ft_strdup(f->gnl.line + 4);
		f->grid.count.x+= 1;	
		f->grid.count.y+= 1;
	}
	f->grid.grid[f->grid.height] = 0;
}

void		get_piece(t_filler *f)
{
	if (f->turn > 0)
	{
//		int i = 0;
//		while (f->you.toke[i])
//		{
//			ft_strclr(f->you.toke[i]);
//			free (f->you.toke[i]);
//			i++;
//		}
		free (f->you.toke);
		f->you.length = 0;
		f->you.height = 0;
	}
	f->you.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
	f->you.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
	f->you.toke = (char **)ft_memalloc(sizeof(char *) * f->you.height + 1);

	while (f->you.count.y <= f->you.height  &&
			(f->gnl.strbuf = get_next_line(f->gnl.fd, &(f->gnl.line))) == 1)
	{
		f->you.toke[f->you.count.y] = (char *)ft_strdup(f->gnl.line);
		f->you.count.x+= 1;	
		f->you.count.y+= 1;
	}
	f->turn+= 1;
	f->you.toke[f->you.height] = 0; // close the piece	
}

void	ft_print(t_filler *f) // just a checker - delete in the end
{
	ft_putnbr(f->turn);
	ft_putchar('\n');

	ft_puttab(f->grid.grid); // get rid of this check
	ft_putchar('\n');
	ft_puttab(f->you.toke); // get rid of this check
	ft_putchar('\n');
}

/*int		ft_turn(t_filler *f) // function to inform get_piece and place piece whether it is your turn or not
{
	if (f->you.p_id == 'X')
	{
		if (f->turn % 2 == 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if (f->turn % 2 == 1)
			return (1);
		else
			return (0);
	}
}*/

int		main (void)
{
	t_filler	*f;

	f = ft_memalloc(sizeof(t_filler));
	f->turn = 0;
	f->grid.height = 0;
	f->you.height = 0;
	f->you.count.x = 0;
	f->you.count.y = 0;
	f->grid.count.x = 0;
	f->grid.count.y = 0;
	f->gnl.fd = open( "outgame", O_RDONLY); //0;
	f->gnl.line = NULL;

	while ((f->gnl.strbuf = get_next_line(f->gnl.fd, &(f->gnl.line))) == 1)
	{
		// Logic for retrieving piece
		if (ft_contain_char(f->gnl.line, '$'))
			get_player(f);
		// Logic for grid. no need to re-alloc//
		if (ft_strstr_io(f->gnl.line, STARTXY) == 0)
		{
			f->grid.count.x = 0;
			f->grid.count.y = 0;
			get_map(f);
		}
		// Logic for piece_ must re-alloc//
		if (ft_strstr_io(f->gnl.line, TOKE) == 0) //&& ft_turn(f) == 1)
		{
			f->grid.count.x = 0;
			f->grid.count.y = 0;
			get_piece(f);
		}
		place_map(f); // strategy will be initiated from place
	}
	close(f->gnl.fd);
	return 0;
}
