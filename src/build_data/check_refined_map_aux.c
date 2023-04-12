/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_refined_map_aux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:53:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:03:18 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_walls_aux(char **map)
{
	int	index;
	int	len;

	index = 0;
	while (map[index])
	{
		len = ft_strlen(map[index]);
		if (ft_strchr("NSEW0", map[index][0])
				|| ft_strchr("NSEW0", map[index][len - 1]))
			return (1);
		index++;
	}
	return (0);
}

int	check_walls(t_map *map)
{
	int	x;
	int	len;
	int	size_map;

	x = 0;
	size_map = ft_matrix_strlen(map->map_matrix);
	if (check_walls_aux(map->map_matrix))
		return (1);
	len = ft_strlen(map->map_matrix[0]);
	while (x < len)
	{
		if (ft_strchr("NSEW0", map->map_matrix[0][x]))
			return (1);
		x++;
	}
	len = ft_strlen(map->map_matrix[size_map - 1]);
	while (x < len)
	{
		if (ft_strchr("NSEW0", map->map_matrix[size_map - 1][x]))
			return (1);
		x++;
	}
	return (0);
}

static int	check_line(char *line)
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	while (line[index] != '\0')
	{
		if (line[index] == 'N' || line[index] == 'S'
			|| line[index] == 'E' || line[index] == 'W')
			result++;
		index++;
	}
	return (result);
}

int	check_player(char **map)
{
	int	index;
	int	qt_persons;

	index = 0;
	qt_persons = 0;
	while (map[index] != NULL)
	{
		qt_persons += check_line(map[index]);
		index++;
	}
	if (qt_persons != 1)
		return (1);
	return (0);
}
