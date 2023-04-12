/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_refined_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:36:45 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:00:21 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_spaces_aux(char **map, int i)
{
	int	index;

	index = 0;
	while (map[i][index])
	{
		if (map[i][index] == ' ')
		{
			if (map[i][index + 1] && ft_strchr("NSEW0", map[i][index + 1]))
				return (1);
			if ((index > 0) && ft_strchr("NSEW0", map[i][index - 1]))
				return (1);
			if (map[i + 1] != NULL && map[i + 1][index]
					&& ft_strchr("NSEW0", map[i + 1][index]))
				return (1);
			if ((i > 0) && ft_strchr("NSEW0", map[i - 1][index]))
				return (1);
		}
		index++;
	}
	return (0);
}

static int	check_spaces(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_matrix[i])
	{
		if (check_spaces_aux(map->map_matrix, i))
			return (1);
		i++;
	}
	return (0);
}

static int	check_characters_map(char **map)
{
	int		index;
	int		count;
	char	temp;

	index = 0;
	while (map[index] != NULL)
	{
		count = 0;
		while (map[index][count])
		{
			temp = map[index][count];
			if (temp == ' ' || temp == '1' || temp == '0'
				|| temp == 'N' || temp == 'E' || temp == 'W' || temp == 'S' )
				count++;
			else
				return (1);
		}
		index++;
	}
	return (0);
}

int	check_refined_map(t_data *data)
{
	if (check_walls(data->map))
	{
		printf("Error\nMap walls are wrong\n");
		return (1);
	}
	if (check_spaces(data->map))
	{
		printf("Error\nThe walls of the map are not correctly closed\n");
		return (1);
	}
	if (check_player(data->map->map_matrix))
	{
		printf("Error\nThe player is wrong\n");
		return (1);
	}
	if (check_characters_map(data->map->map_matrix))
	{
		printf("Error\nWrong character in map\n");
		return (1);
	}
	return (0);
}
