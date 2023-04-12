/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:14:01 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:14:21 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_map(t_map *map)
{
	if (map == NULL)
		return ;
	ft_strdel(&map->patch);
	ft_strdel(&map->no_path);
	ft_strdel(&map->so_path);
	ft_strdel(&map->we_path);
	ft_strdel(&map->ea_path);
	ft_strdel(&map->str_floor);
	ft_strdel(&map->str_sky);
	ft_matrix_strdel(map->map_matrix);
	free(map);
	map = NULL;
}

static void	destroy_player(t_player *player)
{
	if (player == NULL)
		return ;
	free (player);
}

void	destroy_image(t_data *data)
{
	if (data->image->pont)
		mlx_destroy_image(data->mlx, data->image->pont);
	free (data->image);
}

int	destroy(t_data *data)
{
	data->close_game = 1;
	if (data == NULL)
		return (1);
	destroy_rays(data);
	destroy_player(data->player);
	destroy_image(data);
	destroy_texture(data);
	destroy_map(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free (data->mlx);
	}
	free(data);
	data = NULL;
	exit (0);
	return (0);
}
