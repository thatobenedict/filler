/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/13 14:23:07 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		ft_strstr_io(const char *haystack, const char *needle); // add to libft

int		main(int ac, char *av[])
{
	int		fd;
	int		strbuf;
	char	*line;
	int		i = 0;
	t_piece you;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		line = NULL;
		while ((strbuf = get_next_line(fd, &line)) == 1 && i < 5)
			i++;
		while ((strbuf = get_next_line(fd, &line)) == 1)
		{
			printf("%i |%s|\n\n",i, line);
			if (i == 5 && ft_strstr_io(line, PLAYER) == 0)
				you.p_id = 0;
			if (i == 7 && ft_strstr_io(line, PLAYER) == 0)
				you.p_id = 1;
			i++;
		}
		i = 0;
		printf("%d", you.p_id);
		close(fd);
	}
	return 0;
}
