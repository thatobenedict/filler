/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/17 18:07:03 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		ft_strstr_io(const char *haystack, const char *needle); // add to libft

int		main(int ac, char *av[])
{
	t_gnl		gnl;
	t_cord		p;
	t_grid		grid;
	t_piece 	you;

	if (ac > 1)
	{
		gnl.fd = open(av[1], O_RDONLY);
		gnl.line = NULL;
		while ((gnl.strbuf = get_next_line(gnl.fd, &(gnl.line))) == 1 && p.x < 5)
			p.x++;
		while ((gnl.strbuf = get_next_line(gnl.fd, &(gnl.line))) == 1)
		{
			printf("%i |%s|\n\n",p.x, gnl.line);
			if (p.x == 5 && ft_strstr_io(gnl.line, PLAYER) == 0)
				you.p_id = 0;
			if (p.x == 7 && ft_strstr_io(gnl.line, PLAYER) == 0)
				you.p_id = 1;
			if (p.x == 8 && ft_strstr_io(gnl.line, STARTXY) == 0)
			{
				grid.length = ft_atoi(ft_strsplit_word(gnl.line, ' ', 3));
				grid.height = ft_atoi(ft_strsplit_word(gnl.line, ' ', 2));
			}
			if (p.x > 9 && p.x <= (9 + grid.height))
			{
				if (p.x == 10)
					grid.grid = (char **)ft_memalloc(sizeof(char *) * grid.height + 1);
				grid.grid[p.y] = (char *)ft_strdup(gnl.line + 4);
				p.y++;
				if (p.y == grid.height + 1)
					grid.grid[p.y] = 0;
			}
			if (p.x == 10 + grid.height && ft_strstr_io(gnl.line, TOKE) == 0)
			{
				you.length = ft_atoi(ft_strsplit_word(gnl.line, ' ', 3));
				you.height = ft_atoi(ft_strsplit_word(gnl.line, ' ', 2));
			}
			if (p.x > 10 + grid.height && p.x <= (10 + grid.height + you.height))
			{
				if (p.x == 10 + grid.height)
					you.piece = (char **)ft_memalloc(sizeof(char *) * you.height + 1);
				you.piece[p.y] = (char *)ft_strdup(gnl.line);
				p.y++;
				if (p.y == you.height + 1)
					you.piece[p.y] = 0;
			}
				p.x++;
		}
		p.x = 0;
		printf("\n\n\n%d", you.p_id);
		printf("\n%d", grid.length);
		printf("\n%d\n", grid.height);
		while (p.x < grid.height)
		{
			printf("%s\n", grid.grid[p.x]);
			p.x++;
		}
		close(gnl.fd);
	}
	return 0;
}
