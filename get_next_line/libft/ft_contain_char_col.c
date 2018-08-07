/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain_char_col.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:08:24 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/07 15:30:36 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_contain_char_col(char **s, int col, int height, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (i < height)
	{
		if (s[i][col] == (char)c)
			return (1);
		else
			i++;
	}
	return (0);
}
