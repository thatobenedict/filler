/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:08:34 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/03 18:14:47 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define PLAYER "carli"
# define STARTXY "Plateau"
# define TOKE "Piece"
# include "get_next_line/get_next_line.h"

typedef struct	s_cord
{
	int			x;
	int			y;
}				t_cord;

typedef struct  s_grid
{
	int			height;
	int			length;
	t_cord		count;
	char		**grid;
}				t_grid;

typedef struct	s_piece
{
	int			p_id;	
	int			height;
	int			length;
	t_cord		count;
	char		**toke;
	t_cord		start;
}				t_piece;

typedef struct  s_gnl
{
	int			fd;
	int			strbuf;
	char		*line;
}				t_gnl;

typedef struct	s_offset
{
	t_cord		tl;
	t_cord		tr;
	t_cord		br;
	t_cord		bl;
	char		**trim;
}				t_offset;

typedef struct  s_place
{
	t_cord		piece;
	t_cord		count;
}				t_place;

typedef struct	s_filler	
{
	t_piece		you;
//	t_grid		token;
	t_piece		opp;
	t_grid		grid;
	t_gnl		gnl;
	t_place		place;
	int			turn;
	t_offset	trim;
}				t_filler;
#endif
