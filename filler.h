/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:08:34 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/07 18:27:21 by tbenedic         ###   ########.fr       */
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
	t_cord		top;
	t_cord		bottom;
	t_cord		right;
	t_cord		left;
	char		**trim;
	t_cord		new_toke;
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

void	top(t_filler	*f);
void	bottom(t_filler	*f);
void	left(t_filler	*f);
void	right(t_filler	*f);
int		star_match(t_filler *f, int m_i, int m_j);
void	place_map(t_filler	*f);
void	trim_piece(t_filler	*f);
void	valid_move(t_filler  *f);
//TEMP
int		fd;
int		count;
#endif
