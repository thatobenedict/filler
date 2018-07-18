/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/18 18:15:16 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		ft_strstr_io(const char *haystack, const char *needle); // add to libft

int		main(int ac, char *av[])
{
	t_gnl		gnl;
	t_grid		grid;
	t_piece 	you;

	if (ac > 1)
	{
		gnl.fd = open(av[1], O_RDONLY);
		gnl.line = NULL;
		while ((gnl.strbuf = get_next_line(gnl.fd, &(gnl.line))) == 1 && grid.count.x < 5)
			grid.count.x++;
		while ((gnl.strbuf = get_next_line(gnl.fd, &(gnl.line))) == 1)
		{
			printf("%i |%s|\n\n",grid.count.x, gnl.line);
			if (grid.count.x == 5 && ft_strstr_io(gnl.line, PLAYER) == 0)
				you.p_id = 0;
			if (grid.count.x == 7 && ft_strstr_io(gnl.line, PLAYER) == 0)
				you.p_id = 1;
			if (grid.count.x == 8 && ft_strstr_io(gnl.line, STARTXY) == 0)
			{
				grid.length = ft_atoi(ft_strsplit_word(gnl.line, ' ', 3));
				grid.height = ft_atoi(ft_strsplit_word(gnl.line, ' ', 2));
			}
			if (grid.count.x > 9 && grid.count.x <= (9 + grid.height))
			{
				if (grid.count.x == 10)
					grid.grid = (char **)ft_memalloc(sizeof(char *) * grid.height + 1);
				grid.grid[grid.count.y] = (char *)ft_strdup(gnl.line + 4);
				grid.count.y++;
				if (grid.count.y == grid.height + 1)
					grid.grid[grid.count.y] = 0;
			}
			//Logic for piece//
		//	if (grid.count.x == 9 + grid.height && ft_strstr_io(gnl.line, TOKE) == 0)
	/*		if (ft_strstr_io(gnl.line, TOKE) == 0)
			{
				you.length = ft_atoi(ft_strsplit_word(gnl.line, ' ', 3));
				you.height = ft_atoi(ft_strsplit_word(gnl.line, ' ', 2));
				printf("piece length A|||| %i\n", you.length);
				printf("piece height A|||| %i\n", you.height);
			}
			if (you.count.x > 9 + grid.height && you.count.x <= (10 + grid.height + you.height))
			{
				if (you.count.x == 10 + grid.height)
					you.piece = (char **)ft_memalloc(sizeof(char *) * you.height + 1);
				you.piece[you.count.y] = (char *)ft_strdup(gnl.line);
				you.count.y++;
				if (you.count.y == you.height + 1)
					you.piece[you.count.y] = 0;
			}
				you.count.x++; */
		}
		grid.count.x = 0;
		printf("\n\n\n%d", you.p_id);
		printf("\n%d", grid.length);
		printf("\n%d\n", grid.height);
//		printf("piece length C|||| %i\n", you.length);
//		printf("piece height C|||| %i\n", you.height);

		while (grid.count.x < grid.height)
		{
			printf("%s\n", grid.grid[grid.count.x]);
			grid.count.x++;
		}
		you.count.x = 0;
/*		printf("piece length D|||| %i\n", you.length - 1);
		printf("piece height D|||| %i\n", you.height - 1);
		while (you.count.x < you.height)
		{
			printf("%s\n", you.piece[you.count.x]);
			you.count.x++;
		}*/
		close(gnl.fd);
	}
	return 0;
}
