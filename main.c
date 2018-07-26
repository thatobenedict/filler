/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/26 15:46:37 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cord	top_left(char	**piece, int x, int y);
t_cord	place_map(char	**grid, int id);

//int		main(int ac, char *av[])
int		main (void)
{
	t_filler	*f;

//	if (ac > 1)
//	{
		f = ft_memalloc(sizeof(t_filler));

		f->grid.height = 0;
		f->you.height = 0;
		f->you.count.y = 0;
		f->grid.count.y = 0;
		f->gnl.fd = 0;//open(av[1], O_RDONLY);
		f->gnl.line = NULL;
//		while ((f->gnl.strbuf = get_next_line(f->gnl.fd, &(f->gnl.line))) == 1 && f->grid.count.x < 5)
//			f->grid.count.x++;
		while ((f->gnl.strbuf = get_next_line(f->gnl.fd, &(f->gnl.line))) == 1)
		{
			if (ft_contain_char(f->gnl.line, '$'))
				f->you.p_id	= (f->gnl.line[10] == 1) ? 'X' : 'O';
		// Snatch the player_id
		//	if (f->grid.count.x == 5 && ft_strstr_io(f->gnl.line, PLAYER) == 0)
		//		f->you.p_id = 0;
		//	if (f->grid.count.x == 7 && ft_strstr_io(f->gnl.line, PLAYER) == 0)
		//		f->you.p_id = 1;

			// Logic for grid. no need to re-alloc//
			else if (ft_strstr_io(f->gnl.line, STARTXY) == 0 && f->grid.count.x++ < 5)
			{
				f->grid.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
				f->grid.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
				f->grid.grid= (char **)ft_memalloc(sizeof(char *) * f->grid.height + 1);
			}
			else if (f->grid.count.x > 1 && f->grid.count.x <= (1 + f->grid.height))
			{
				f->grid.grid[f->grid.count.y] = (char *)ft_strdup(f->gnl.line + 4);
				f->grid.count.y++;
			}

			// Logic for piece_ must re-alloc//
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
