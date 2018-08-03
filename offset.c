/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:11:37 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/03 17:18:16 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	top_left(t_filler	*f)
{
	f->trim.tl.x = 0;
	f->trim.tl.y = 0;

	while (f->you.toke[f->trim.tl.x] != 0)
	{
		f->trim.tl.y = 0;
		while (f->you.toke[f->trim.tl.x][f->trim.tl.y] != '\0')
		{
			if (f->you.toke[f->trim.tl.x][f->trim.tl.y] == '*')
				break ;	
			f->trim.tl.y++;
		}
		if (f->you.toke[f->trim.tl.x][f->trim.tl.y] == '*')
			break ;	
		f->trim.tl.x++;
	}
}

void	bot_right(t_filler	*f)
{

	f->trim.br.x = 0;
	while (f->you.toke[f->trim.br.x] != 0)
		f->trim.br.x++;
	f->trim.br.y = ft_strlen(f->you.toke[0]);

	while (f->you.toke[f->trim.br.x] != 0)
	{
		f->trim.br.y = ft_strlen(f->you.toke[0]);
		while (f->you.toke[f->trim.br.x][f->trim.br.y] != '\0')
		{
			if (f->you.toke[f->trim.br.x][f->trim.br.y] == '*')
				break ;	
			f->trim.br.y--;
		}
		if (f->you.toke[f->trim.br.x][f->trim.br.y] == '*')
			break ;	
		f->trim.br.x--;
	}
}

/*
   t_cord		bot_right(char	**piece, int x, int y)
   {
   t_cord	count;
   int hold = y;

   while (x >= 0)
   {
   y = hold;
   while (x >= 0 && y >= 0)
   {
   if (piece[x][y] == '*')
   break ;	
   y--;
   }
   if (piece[x][y] == '*')
   break ;	
   x--;
   }
   count.x = x;
   count.y = y;
   ft_putnbr(count.x);
   ft_putchar(' ');
   ft_putnbr(count.y);
   ft_putchar('\n');
   return (count);
   }


   t_cord  top_right(char  **piece, int x, int y)
   {
   t_cord	count;
   int 	i;

   i = 0;
   while (y >= 0)
   {
   i = 0;
   while (i < x)
   {
   if (piece[i][y] == '*')
   break ;	
   i++;
   }
   if (piece[i][y] == '*')
   break ;
   y--;
   }
   count.x = i;
   count.y = y;
   ft_putnbr(count.x);
   ft_putchar(' ');
   ft_putnbr(count.y);
   ft_putchar('\n');
   return (count);
   }

   t_cord  bot_right(char  **piece, int x, int y);
   t_cord  bot_left(char   **piece, int x, int y);*/
