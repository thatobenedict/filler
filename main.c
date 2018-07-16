/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/16 17:40:54 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		ft_strstr_io(const char *haystack, const char *needle); // add to libft

int		main(int ac, char *av[])
{
	t_gnl	gnl;
	int		i = 0;
	int		j = 0;
	t_grid	grid;
	t_piece you;

	if (ac > 1)
	{
		gnl.fd = open(av[1], O_RDONLY);
		gnl.line = NULL;
		while ((gnl.strbuf = get_next_line(gnl.fd, &(gnl.line))) == 1 && i < 5)
			i++;
		while ((gnl.strbuf = get_next_line(gnl.fd, &(gnl.line))) == 1)
		{
			printf("%i |%s|\n\n",i, gnl.line);
			if (i == 5 && ft_strstr_io(gnl.line, PLAYER) == 0)
				you.p_id = 0;
			if (i == 7 && ft_strstr_io(gnl.line, PLAYER) == 0)
				you.p_id = 1;
			if (i == 8 && ft_strstr_io(gnl.line, STARTXY) == 0)
			{
				grid.length = ft_atoi(ft_strsplit_word(gnl.line, ' ', 3));
				grid.height = ft_atoi(ft_strsplit_word(gnl.line, ' ', 2));
			}
			if (i > 9 && i <= (9 + grid.height))
			{
				if (i == 10)
					grid.grid = (char **)ft_memalloc(sizeof(char *) * grid.height + 1);
				grid.grid[j] = (char *)ft_strdup(gnl.line + 4);
				j++;
				//i++;
				if (j == grid.height + 1)
					grid.grid[j] = 0;
			}
			i++;
		}
		i = 0;
		printf("\n\n\n%d", you.p_id);
		printf("\n%d", grid.length);
		printf("\n%d\n", grid.height);
		while (i < grid.height)
		{
			printf("%s\n", grid.grid[i]);
			i++;
		}
		close(gnl.fd);
	}
	return 0;
}
