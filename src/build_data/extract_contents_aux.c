/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_contents_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:32:21 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:33:13 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*complet_line(int columns, char *line)
{
	int		index;
	int		size_line;
	char	*result;

	index = 0;
	size_line = ft_strlen(line);
	result = NULL;
	result = ft_calloc(sizeof(char), columns + 1);
	while (index < columns)
	{
		if (index < size_line)
			result[index] = line[index];
		else
			result[index] = ' ';
		index++;
	}
	result[index] = '\0';
	return (result);
}

static void	map_size(t_data *data, char **file)
{
	int		index;
	int		lines;
	size_t	columns;

	index = 0;
	lines = 0;
	columns = 0;
	while (file[index] != NULL)
	{
		if (is_line_map(file[index]))
		{
			if (columns < ft_strlen(file[index]))
				columns = ft_strlen(file[index]);
			lines++;
		}
		index++;
	}
	data->map->nb_columns = columns;
	data->map->nb_lines = lines;
	data->map->height_px = lines * TILE_SIZE;
	data->map->width_px = columns * TILE_SIZE;
}

void	extract_map(t_data *data, char **file)
{
	int		index;
	char	*temp;
	char	**result;

	index = 0;
	result = NULL;
	temp = NULL;
	map_size(data, file);
	while (file[index] != NULL)
	{
		if (is_line_map(file[index]))
		{
			temp = complet_line(data->map->nb_columns, file[index]);
			result = ft_matrix_join(result, temp);
			ft_strdel(&temp);
			temp = NULL;
		}
		index++;
	}
	data->map->map_matrix = result;
}
