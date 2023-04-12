/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:54:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 16:45:18 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist_between_points(double x1, double y1, double x2, double y2)
{
	double	ret;

	ret = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return (ret);
}

static void	calc_dist(t_data *data, t_ray *ray)
{
	if (ray->hrz->found_wall)
		ray->hrz->distance = dist_between_points(data->player->pos_x,
				data->player->pos_y, ray->hrz->wall_x, ray->hrz->wall_y);
	else
		ray->hrz->distance = MAX_INT;
	if (ray->vert->found_wall)
		ray->vert->distance = dist_between_points(data->player->pos_x,
				data->player->pos_y, ray->vert->wall_x, ray->vert->wall_y);
	else
		ray->vert->distance = MAX_INT;
	if (ray->vert->distance < ray->hrz->distance)
	{
		ray->distance = ray->vert->distance
			* cos(normalize_angle(data->player->angle - ray->ray_angle));
		ray->vertical_wall = 1;
	}
	else
	{
		ray->distance = ray->hrz->distance
			* cos(normalize_angle(data->player->angle - ray->ray_angle));
		ray->vertical_wall = 0;
	}
}

void	clear_inter(t_inter *inter)
{
	inter->found_wall = 0;
	inter->wall_x = 0;
	inter->wall_y = 0;
	inter->step_x = 0;
	inter->step_y = 0;
	inter->distance = 0;
}

void	clear_ray(t_ray *ray)
{
	clear_inter(ray->hrz);
	clear_inter(ray->vert);
	ray->render->proj_wall_height = 0;
	ray->render->wall_bottom_pixel = 0;
	ray->render->wall_top_pixel = 0;
	ray->render->wall_strip_height = 0;
	ray->ray_angle = 0;
	ray->distance = 0;
	ray->vertical_wall = 0;
	ray->is_facing_down = 0;
	ray->is_facing_up = 0;
	ray->is_facing_right = 0;
	ray->is_facing_left = 0;
}

void	raycasting(t_data *data)
{
	double	ray_angle;
	int		column_id;

	ray_angle = normalize_angle(data->player->angle + (FOV_ANGLE / 2));
	column_id = 0;
	while (column_id < NUM_RAYS)
	{
		clear_ray(&data->rays[column_id]);
		data->rays[column_id].ray_angle = ray_angle;
		project_rays(data, &data->rays[column_id]);
		calc_dist(data, &data->rays[column_id]);
		ray_angle = normalize_angle(ray_angle - FOV_ANGLE / NUM_RAYS);
		column_id++;
	}
	render_3d_projected_walls(data);
}
