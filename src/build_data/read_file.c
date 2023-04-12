/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:46:49 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 02:31:33 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_file(char *patch, int *fd)
{
	*fd = open(patch, O_RDONLY);
	if (*fd == -1)
		return (1);
	return (0);
}

static char	**load_file(int fd)
{
	int		count;
	char	*line;
	char	**file;

	line = NULL;
	file = NULL;
	count = get_next_line(fd, &line);
	file = ft_matrix_join(NULL, line);
	ft_strdel(&line);
	while (count)
	{
		line = NULL;
		count = get_next_line(fd, &line);
		file = ft_matrix_join(file, line);
		ft_strdel(&line);
	}
	return (file);
}

char	**read_file(t_data *data)
{
	int		fd;
	char	**file;

	file = NULL;
	if (open_file(data->map->patch, &fd))
	{
		printf("Error\nUnable to open the file %s\n", data->map->patch);
		return (NULL);
	}
	file = load_file(fd);
	close(fd);
	return (file);
}
