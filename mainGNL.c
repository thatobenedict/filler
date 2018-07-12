/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:10:34 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/12 17:44:35 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>
#include <string.h>

int		main(int ac, char *av[])
{
	int		fd;
	int		strbuf;
	char	*line;
	int		i = 0;
	int 	j = 1;

	if (ac > 1)
	{
		while (j < ac)
		{
		fd = open(av[j], O_RDONLY, 0700);
		printf("%d\n", fd);
		line = NULL;
		while ((strbuf = get_next_line(fd, &line)) == 1)
		{
			printf("%i |%s|\n\n",i, line);
			i++;
		}
		j++;
		i = 0;
		}
		close(fd);
	}
	return 0;
}
