/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:59:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/05 18:24:10 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		get_player(t_filler		*f)
{
	get_next_line(f->gnl.fd, &(f->gnl.line));	
	count++; // DELETE ME
	f->you.p_id	= (f->gnl.line[10] == '1') ? 'O' : 'X';
	f->opp.p_id	= (f->gnl.line[10] == '1') ? 'X' : 'O';
	/*	///////DELETE WHEN DONE///////
		if (f->turn == 0)
		{
		fd = open ("gnl", O_WRONLY);
		ft_putstr_fd(f->gnl.line, fd);
		ft_putchar_fd('\n', fd);	
		ft_putstr_fd("Line ", fd);
		ft_putnbr_fd(count, fd);
		ft_putchar_fd('\n', fd);
		ft_putchar_fd('\n', fd);
		count++;
		close (fd);
		}
		*/	///////DELETE WHEN DONE///////
}

void		get_map(t_filler *f)
{
	get_next_line(f->gnl.fd, &(f->gnl.line));
	count++; // DELETEME
	/*	///////DELETE WHEN DONE///////
		if (f->turn == 0)
		{
		fd = open ("gnl", O_RDWR);
		ft_putstr_fd(f->gnl.line, fd);
		ft_putchar_fd('\n', fd);	
		ft_putstr_fd("Line ", fd);
		ft_putnbr_fd(count, fd);
		ft_putchar_fd('\n', fd);
		ft_putchar_fd('\n', fd);
		count++;
		close (fd);
		}
		*/	///////DELETE WHEN DONE///////
	int i = 0;
	if (f->turn == 0)
	{
		f->grid.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
		f->grid.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
		f->grid.grid = (char **)ft_memalloc(sizeof(char *) * f->grid.height + 1);
	}
	get_next_line(f->gnl.fd, &(f->gnl.line));	
	count++; // DELETEME
	///////DELETE WHEN DONE///////
	/*	if (f->turn == 0)
		{
		fd = open ("gnl", O_WRONLY);
		ft_putstr_fd(f->gnl.line, fd);
		ft_putchar_fd('\n', fd);	
		ft_putstr_fd("Line ", fd);
		ft_putnbr_fd(count, fd);
		ft_putchar_fd('\n', fd);
		ft_putchar_fd('\n', fd);
		count++;
		close (fd);
		}
		*/	///////DELETE WHEN DONE///////


	while (i < (f->grid.height) )
	{
		get_next_line(f->gnl.fd, &(f->gnl.line));
		count++; // DELETEME
		f->grid.grid[i] = (char *)ft_strdup(f->gnl.line + 4);
		i++;
	}
	f->grid.grid[f->grid.height] = 0;
	/*	///////DELETE WHEN DONE///////
		if (f->turn == 0)
		{
		fd = open ("gnl", O_RDWR, O_CREAT);
		ft_puttab_fd(f->grid.grid, fd);
	//	ft_putstr_fd(f->gnl.line, fd);
	//	ft_putchar_fd('\n', fd);	
	//	ft_putstr_fd("Line ", fd);
	//	ft_putnbr_fd(count, fd);
	//	ft_putchar_fd('\n', fd);
	//	ft_putchar_fd('\n', fd);
	//	count++;
	close (fd);
	}
	*/	///////DELETE WHEN DONE///////

}

void		get_piece(t_filler *f)
{
	get_next_line(f->gnl.fd, &(f->gnl.line));
	/*		///////DELETE WHEN DONE///////
			if (f->turn == 0)
			{
			fd = open ("gnl", O_WRONLY);
			ft_putstr_fd(f->gnl.line, fd);
			ft_putchar_fd('\n', fd);	
			ft_putstr_fd("Line ", fd);
			ft_putnbr_fd(count, fd);
			ft_putchar_fd('\n', fd);
			count++;
			close (fd);
			}
			*/	///////DELETE WHEN DONE///////
	if (f->turn > 0)
	{
		free (f->you.toke);
		f->you.length = 0;
		f->you.height = 0;
	}
	f->you.length = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 3));
	f->you.height = ft_atoi(ft_strsplit_word(f->gnl.line, ' ', 2));
	f->you.toke = (char **)ft_memalloc(sizeof(char *) * f->you.height + 1);
	int i = 0;
	while (i < f->you.height)
	{
		get_next_line(f->gnl.fd, &(f->gnl.line));	
		f->you.toke[i] = (char *)ft_strdup(f->gnl.line);
		i++;
	}
	f->turn+= 1;
	f->you.toke[f->you.height] = 0;

/*	///////DELETE WHEN DONE///////
	if (f->turn == 1)
	{
		fd = open ("gnl", O_RDWR, O_CREAT);
		ft_puttab_fd(f->you.toke, fd);
		close (fd);
	}
*/	///////DELETE WHEN DONE///////
}

void	ft_print(t_filler *f) // delete in the end
{
	//	ft_putnbr(f->turn);
	//	ft_putchar('\n');

	//	ft_puttab(f->grid.grid); // get rid of this check
	//	ft_putchar('\n');
	ft_puttab(f->you.toke); // get rid of this check
	ft_putchar('\n');
}

int		ft_turn(t_filler *f) // function to inform get_piece and place piece whether it is your turn or not
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
}

void	ft_initial(t_filler		*f)
{
	f->turn = 0;
	f->grid.height = 0;
	f->you.height = 0;
	f->you.count.x = 0;
	f->you.count.y = 0;
	f->grid.count.x = 0;
	f->grid.count.y = 0;
	f->gnl.fd = 0 ;
	f->gnl.line = NULL;
}

int		main (void)
{
	t_filler	*f;
	f = ft_memalloc(sizeof(t_filler));
	ft_initial(f);
	get_player(f);
	while (1)
	{
		get_map(f);
		get_piece(f);
		trim_piece(f);
		place_map(f); // strategy will be initiated from place
	}
	return 0;
}
