/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:15:07 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:18:21 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sky(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->render->wall_top_pixel)
	{
		draw_pixel_color(data->image, x, y, data->map->color_sky);
		y++;
	}
}

static void	draw_bottom(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = ray->render->wall_bottom_pixel;
	while (y < WIN_HEIGHT)
	{
		draw_pixel_color(data->image, x, y, data->map->color_floor);
		y++;
	}
}

static void	calculate_columns(t_ray *ray)
{
	ray->render->wall_top_pixel = (WIN_HEIGHT / 2)
		- (ray->render->proj_wall_height / 2);
	if (ray->render->wall_top_pixel < 0)
		ray->render->wall_top_pixel = 0;
	ray->render->wall_bottom_pixel = (WIN_HEIGHT / 2)
		+ (ray->render->proj_wall_height / 2);
	if (ray->render->wall_bottom_pixel > WIN_HEIGHT)
		ray->render->wall_bottom_pixel = WIN_HEIGHT;
}

void	render_3d_projected_walls(t_data *data)
{
	int		x;
	t_ray	*ray;

	x = 0;
	while (x < NUM_RAYS)
	{
		ray = &data->rays[x];
		ray->render->proj_wall_height = (TILE_SIZE / ray->distance)
			* data->dist_proj_plane;
		ray->render->wall_strip_height = ceil(ray->render->proj_wall_height);
		calculate_columns(ray);
		draw_sky(data, ray, x);
		draw_wall(data, ray, x);
		draw_bottom(data, ray, x);
		x++;
	}
}
