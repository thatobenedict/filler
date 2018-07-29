/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:11:37 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/29 13:11:37 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cord		top_left(char	**piece, int x, int y)
{
	t_cord	count;

	while (piece[x] != 0)
	{
		y = 0;
		while (piece[x][y] != '\0')
		{
			if (piece[x][y] == '*')
				break ;	
			y++;
		}
		if (piece[x][y] == '*')
			break ;	
		x++;
	}
	count.x = x;
	count.y = y;
	ft_putnbr(count.x);
	ft_putchar(' ');
	ft_putnbr(count.y);
	ft_putchar('\n');
	return (count);
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
