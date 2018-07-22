/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:08:34 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/22 12:27:37 by tbenedic         ###   ########.fr       */
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
	char		**piece;
	t_cord		start;
}				t_piece;

typedef struct  s_gnl
{
	int			fd;
	int			strbuf;
	char		*line;
}				t_gnl;

typedef struct	s_filler	
{
	t_piece		p_1;
	t_grid		token;
	t_piece		p_2;
	t_grid		map;
	t_gnl		gnl;
}				t_filler;

#endif
