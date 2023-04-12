/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:04:51 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:07:11 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_render	*init_render(void)
{
	t_render	*render;

	render = NULL;
	render = ft_calloc(sizeof(t_render), 1);
	if (render == NULL)
		return (NULL);
	render->proj_wall_height = 0;
	render->wall_bottom_pixel = 0;
	render->wall_top_pixel = 0;
	render->wall_strip_height = 0;
	return (render);
}

t_inter	*init_inter(void)
{
	t_inter	*result;

	result = NULL;
	result = ft_calloc(sizeof(t_inter), 1);
	result->found_wall = 0;
	result->wall_x = 0;
	result->wall_y = 0;
	result->step_x = 0;
	result->step_y = 0;
	result->distance = 0;
	return (result);
}

void	init_rays(t_data *data)
{
	int	index;

	index = 0;
	while (index < NUM_RAYS)
	{
		data->rays[index].hrz = init_inter();
		data->rays[index].vert = init_inter();
		data->rays[index].render = init_render();
		data->rays[index].ray_angle = 0;
		data->rays[index].distance = 0;
		data->rays[index].vertical_wall = 0;
		data->rays[index].is_facing_down = 0;
		data->rays[index].is_facing_up = 0;
		data->rays[index].is_facing_right = 0;
		data->rays[index].is_facing_left = 0;
		index++;
	}
}
