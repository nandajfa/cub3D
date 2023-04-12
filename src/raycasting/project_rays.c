/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 00:49:24 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 16:49:54 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	where_is_looking(t_ray *ray)
{
	ray->is_facing_up = (ray->ray_angle >= 0 && ray->ray_angle <= PI);
	ray->is_facing_down = !ray->is_facing_up;
	ray->is_facing_right = (ray->ray_angle <= (PI / 2)
			|| ray->ray_angle >= (1.5 * PI));
	ray->is_facing_left = !ray->is_facing_right;
}

void	project_rays(t_data *data, t_ray *ray)
{
	where_is_looking(ray);
	horizontal_intersection(data, ray);
	vertical_intersection(data, ray);
}
