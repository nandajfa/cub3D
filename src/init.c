/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:15:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:05:46 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_image	*init_image(void)
{
	t_image	*image;

	image = NULL;
	image = ft_calloc(sizeof(t_image), 1);
	if (image == NULL)
		return (NULL);
	image->pont = NULL;
	image->patch = NULL;
	return (image);
}

static t_map	*init_map(char *patch)
{
	t_map	*map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	map->patch = NULL;
	if (patch != NULL)
		map->patch = ft_strdup(patch);
	map->map_matrix = NULL;
	map->nb_lines = 0;
	map->nb_columns = 0;
	map->height_px = 0;
	map->width_px = 0;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->str_floor = NULL;
	map->str_sky = NULL;
	return (map);
}

static t_player	*init_player(void)
{
	t_player	*player;

	player = NULL;
	player = ft_calloc(sizeof(t_player), 1);
	if (player == NULL)
		return (NULL);
	player->pos_x = 0;
	player->pos_y = 0;
	player->angle = 0;
	player->turn_speed = (PI / 180);
	return (player);
}

t_data	*init(char *patch)
{
	t_data	*data;

	data = NULL;
	data = ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (NULL);
	data->map = init_map(patch);
	data->image = init_image();
	data->n_texture = NULL;
	data->s_texture = NULL;
	data->w_texture = NULL;
	data->e_texture = NULL;
	data->player = init_player();
	data->dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	init_rays(data);
	data->mlx = NULL;
	data->win = NULL;
	data->close_game = 0;
	return (data);
}
