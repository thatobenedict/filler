/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/23 17:24:37 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cord	top_left(char	**piece, int x, int y);
t_cord	place_map(char	**grid, int id);

int		main(int ac, char *av[])
{
	t_gnl		*gnl;
	t_grid		*grid;
	t_piece		*you;

	if (ac > 1)
	{
		you = ft_memalloc(sizeof(t_piece));
		gnl = ft_memalloc(sizeof(t_gnl));
		grid = ft_memalloc(sizeof(t_grid));
		
		grid->height = 0;
		you->height = 0;
		you->count.y = 0;
		grid->count.y = 0;
		gnl->fd = open(av[1], O_RDONLY);
		gnl->line = NULL;
		while ((gnl->strbuf = get_next_line(gnl->fd, &(gnl->line))) == 1 && grid->count.x < 5)
			grid->count.x++;
		while ((gnl->strbuf = get_next_line(gnl->fd, &(gnl->line))) == 1)
		{
			// Snatch the player_id
			if (grid->count.x == 5 && ft_strstr_io(gnl->line, PLAYER) == 0)
				you->p_id = 0;
			if (grid->count.x == 7 && ft_strstr_io(gnl->line, PLAYER) == 0)
				you->p_id = 1;


			// Logic for grid-> no need to re-alloc//
			if (grid->count.x == 8 && ft_strstr_io(gnl->line, STARTXY) == 0)
			{
				grid->length = ft_atoi(ft_strsplit_word(gnl->line, ' ', 3));
				grid->height = ft_atoi(ft_strsplit_word(gnl->line, ' ', 2));
				grid->grid= (char **)ft_memalloc(sizeof(char *) * grid->height + 1);
			}
			if (grid->count.x > 9 && grid->count.x <= (9 + grid->height))
			{
				grid->grid[grid->count.y] = (char *)ft_strdup(gnl->line + 4);
				grid->count.y++;
			}


			// Logic for piece_ must re-alloc//
			if (grid->count.x == (10 + grid->height) && ft_strstr_io(gnl->line, TOKE) == 0)
			{
				you->length = ft_atoi(ft_strsplit_word(gnl->line, ' ', 3));
				you->height = ft_atoi(ft_strsplit_word(gnl->line, ' ', 2));
				you->piece = (char **)ft_memalloc(sizeof(char *) * you->height + 1);
			}
			if (grid->count.x > (10 + grid->height) && grid->count.x <= (10 + grid->height + you->height))
			{
				you->piece[you->count.y] = (char *)ft_strdup(gnl->line);
				you->count.y++;
			}
			grid->count.x++;	
		}
		grid->grid[grid->height] = 0; // close the grid
		you->piece[you->height] = 0; // close the piece
		ft_puttab(grid->grid);
		ft_puttab(you->piece);

		top_left(you->piece, 0, 0);
		place_map(grid->grid, you->p_id);
	
		close(gnl->fd);
	}
	return 0;
}
