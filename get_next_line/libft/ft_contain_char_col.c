/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain_char_col.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:08:24 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/04 15:19:34 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_contain_char_col(char **s, int col, int c)
{
	int		i;
	int		height;

	if (!s)
		return (0);
	i = 0;
	height = 0;
	while (s[height] != 0)
		height++;
	while (i < height && s[i][col] != c)
		i++;
	if (s[i][col] == (char)c)
		return (1);
	return (0);
}
