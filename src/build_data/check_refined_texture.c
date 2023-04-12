/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_refined_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:36:09 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 16:49:45 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_path(char *path)
{
	if (!(ft_strncmp(path, "./textures/", 11) == 0))
	{
		printf("Error\nInvalid texture dir\n");
		return (1);
	}
	if (!(ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4) == 0))
	{
		printf("Error\nInvalid texture extension\n");
		return (1);
	}
	return (0);
}

int	check_refined_texture(t_data *data)
{
	int	status;

	status = 0;
	status += check_path(data->map->no_path);
	status += check_path(data->map->so_path);
	status += check_path(data->map->we_path);
	status += check_path(data->map->ea_path);
	if (status != 0)
		return (1);
	return (0);
}
