/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:11:37 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/22 17:53:10 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_offset	*off;

t_offset	top_left(t_piece **piece)
{
	int i;
	int j;

	i = 0;	
	while (piece[i] != 0)
	{
		j = 0;
		while (piece[i][j] != '\0' || piece[i][j] != "*")
			j++;
		i++;
	}
	off->tleft.x = i;
	off->tleft.y = j;
	return (off->tleft);
}
void	top_right(t_piece **piece)
{
}
void	bottom_right(t_piece **piece)
{
}
void	bottom_left(t_piece **piece)
{
}

void	offset(t_piece **piece)
