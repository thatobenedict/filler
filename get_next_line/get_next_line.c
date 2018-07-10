/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/07/10 16:17:17 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		new_line_ind(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i);
}

static char		*ft_remainder(char *line)
{
	char	*new;

	new = ft_strchr(line, '\n');
	if ((new != NULL))
	{
		new++;
		new = ft_strdup(new);
	}
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*keep[9999];
	int			buffout;
	char		*temp;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (READ_ERROR);
	if (keep[fd] == NULL)
		keep[fd] = ft_strdup("");
	while ((buffout = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[buffout] = '\0';
		temp = ft_strjoin_2(keep[fd], buf);
		free(keep[fd]);
		keep[fd] = ft_strdup(temp);
		free(temp);
		if (ft_contain_char(keep[fd], '\n'))
			break ;
	}
	if (*keep[fd] == 0 && buffout == 0)
		return (READ_COMPLETE);
	*line = ft_strndup(keep[fd], new_line_ind(keep[fd]));
	keep[fd] = ft_remainder(keep[fd]);
	return (READ_SUCCESS);
}
