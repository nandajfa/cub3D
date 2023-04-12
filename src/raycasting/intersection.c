/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 22:16:16 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_collision(double x, double y, t_data *data)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (x >= data->map->width_px || y >= data->map->height_px)
		return (-1);
	if (x < 0 || i >= data->map->nb_columns
		|| y < 0 || j >= data->map->nb_lines)
		return (-1);
	if (data->map->map_matrix[j][i] == '1')
		return (1);
	else
		return (0);
}

static void	search_hrz_wall(double x, double y, t_data *data, t_ray *ray)
{
	double	intercep_x;
	double	intercep_y;

	intercep_x = x;
	intercep_y = y;
	ray->hrz->found_wall = 0;
	while (intercep_x <= data->map->width_px
		&& intercep_y <= data->map->height_px)
	{
		if (wall_collision(intercep_x, intercep_y, data) == 1)
		{
			ray->hrz->wall_x = intercep_x;
			ray->hrz->wall_y = intercep_y;
			ray->hrz->found_wall = 1;
			break ;
		}
		if (wall_collision(intercep_x, intercep_y, data) == -1)
			break ;
		intercep_x = intercep_x + ray->hrz->step_x;
		intercep_y = intercep_y + ray->hrz->step_y;
	}
}

static void	search_vert_wall(double x, double y, t_data *data, t_ray *ray)
{
	double	intercep_x;
	double	intercep_y;

	intercep_x = x;
	intercep_y = y;
	ray->vert->found_wall = 0;
	while (intercep_x <= data->map->width_px
		&& intercep_y <= data->map->height_px)
	{
		if (wall_collision(intercep_x, intercep_y, data) == 1)
		{
			ray->vert->wall_x = intercep_x;
			ray->vert->wall_y = intercep_y;
			ray->vert->found_wall = 1;
			break ;
		}
		if (wall_collision(intercep_x, intercep_y, data) == -1)
			break ;
		intercep_x = intercep_x + ray->vert->step_x;
		intercep_y = intercep_y + ray->vert->step_y;
	}
}

void	horizontal_intersection(t_data *data, t_ray *ray)
{
	double	intercep_x;
	double	intercep_y;

	intercep_x = 0;
	intercep_y = 0;
	if (tan(ray->ray_angle) == 0)
	{
		ray->hrz->found_wall = 0;
		return ;
	}
	if (ray->is_facing_down)
	{
		intercep_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE + 64;
		ray->hrz->step_y = TILE_SIZE;
		ray->hrz->step_x = -1 * TILE_SIZE / tan(ray->ray_angle);
	}
	else if (ray->is_facing_up)
	{
		intercep_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE - 0.001;
		ray->hrz->step_y = TILE_SIZE * -1;
		ray->hrz->step_x = TILE_SIZE / tan(ray->ray_angle);
	}
	intercep_x = data->player->pos_x
		+ (data->player->pos_y - intercep_y) / tan(ray->ray_angle);
	search_hrz_wall(intercep_x, intercep_y, data, ray);
}

void	vertical_intersection(t_data *data, t_ray *ray)
{
	double	intercep_x;
	double	intercep_y;

	intercep_x = 0;
	intercep_y = 0;
	if (cos(ray->ray_angle) == 0)
	{
		ray->vert->found_wall = 0;
		return ;
	}
	if (ray->is_facing_right)
	{
		intercep_x = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE + 64;
		ray->vert->step_x = TILE_SIZE;
		ray->vert->step_y = -1 * TILE_SIZE * tan(ray->ray_angle);
	}
	else if (ray->is_facing_left)
	{
		intercep_x = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE - 0.001;
		ray->vert->step_x = TILE_SIZE * -1;
		ray->vert->step_y = TILE_SIZE * tan(ray->ray_angle);
	}
	intercep_y = data->player->pos_y
		+ (data->player->pos_x - intercep_x) * tan(ray->ray_angle);
	search_vert_wall(intercep_x, intercep_y, data, ray);
}
