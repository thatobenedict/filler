/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/29 17:56:45 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cord	top_left(char	**piece, int x, int y);
t_cord	place_map(char	**grid, int id);

void		get_player(t_filler		*f)
{
	f->you.p_id	= (f->gnl.line[10] == '1') ? 'X' : 'O';
	f->opp.p_id	= (f->gnl.line[10] == '1') ? 'O' : 'X';
	f->grid.count.x+= 1;	
}

void		get_map(t_filler *f)
{
	if (f->turn == 0)
	{
		f->grid.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
		f->grid.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
		f->grid.grid = (char **)ft_memalloc(sizeof(char *) * f->grid.height + 1);
	}
	else
	{
		f->grid.count.x+= 1;
		while (f->grid.count.x > 1 && f->grid.count.x <= (1 + f->grid.height))
		{
			f->grid.grid[f->grid.count.y] = (char *)ft_strdup(f->gnl.line + 4);
			f->grid.count.x+= 1;	
			f->grid.count.y+= 1;
		}
	}
	f->turn+= 1;
}

void		get_piece(t_filler *f)
{

}

int		main (void)
{
	t_filler	*f;

	f = ft_memalloc(sizeof(t_filler));

	f->turn = 0;
	f->grid.height = 0;
	f->you.height = 0;
	f->you.count.y = 0;
	f->grid.count.y = 0;
	f->gnl.fd = 0; //open(av[1], O_RDONLY);
	f->gnl.line = NULL;

	while ((f->gnl.strbuf = get_next_line(f->gnl.fd, &(f->gnl.line))) == 1)
	{
		if (ft_contain_char(f->gnl.line, '$'))
			get_player(f);

		// Logic for grid. no need to re-alloc//
		else if (ft_strstr_io(f->gnl.line, STARTXY) == 0)
			get_map(f);

		// Logic for piece_ must re-alloc//
		else if (ft_strstr_io(f->gnl.line, TOKE) == 0)
			get_piece(f);

		else if (f->grid.count.x == (2 + f->grid.height) && ft_strstr_io(f->gnl.line, TOKE) == 0)
		{	
			f->you.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
			f->you.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
			f->you.piece = (char **)ft_memalloc(sizeof(char *) * f->you.height + 1);
		}
		if (f->grid.count.x > (2 + f->grid.height) && f->grid.count.x <= (2 + f->grid.height + f->you.height))
		{
			f->you.piece[f->you.count.y] = (char *)ft_strdup(f->gnl.line);
			f->you.count.y++;
		}
		f->grid.count.x++;	
	}
	f->grid.grid[f->grid.height] = 0; // close the grid
	f->you.piece[f->you.height] = 0; // close the piece
	ft_puttab(f->grid.grid);
	ft_puttab(f->you.piece);

	top_left(f->you.piece, 0, 0);
	place_map(f->grid.grid, f->you.p_id);

	close(f->gnl.fd);
	//	}
	return 0;
	}
