/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:07:55 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 19:17:09 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(int fd, char *save, char **temp)
{
	int		return_read;
	char	*buff;
	char	*line;

	buff = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if ((!(buff)) || (!(line)))
		return (-1);
	return_read = 1;
	if (save == NULL)
		return_read = read(fd, line, BUFFER_SIZE);
	else
		ft_strlcpy(line, save, ft_strlen(save) + 1);
	while (ft_linebreak(line) == -1 && return_read > 0)
	{
		return_read = read(fd, buff, BUFFER_SIZE);
		if (return_read == -1)
			return (-1);
		buff[return_read] = '\0';
		if (return_read > 0)
			line = ft_strjoin_free1(line, buff, return_read);
	}
	ft_strdel(&buff);
	*temp = line;
	return (return_read);
}

static char	*get_result(int r_read, char *temp, char **save)
{
	char	*line;
	int		index;

	if (r_read > 0)
		index = ft_linebreak(temp);
	else
	{
		index = ft_strlen(temp);
	}
	if (ft_linebreak(temp) != -1)
	{
		if (save != NULL)
			ft_strdel(save);
		*save = ft_strindexcpy(save, temp, index + 1);
	}
	line = (char *)ft_calloc(sizeof(char), index + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, temp, index + 1);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char		*save;
	char			*temp;
	int				return_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	return_read = get_line(fd, save, &temp);
	if (return_read == -1)
	{
		ft_strdel(&temp);
		return (-1);
	}
	*line = get_result(return_read, temp, &save);
	if (*line == NULL)
		return (-1);
	ft_strdel(&temp);
	if (return_read == 0)
	{
		ft_strdel(&save);
		return (0);
	}
	return (1);
}
