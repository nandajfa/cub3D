/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:13:43 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:14:28 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_texture(t_data *data)
{
	if (data->n_texture)
	{
		if (data->n_texture->pont)
			mlx_destroy_image (data->mlx, data->n_texture->pont);
		free (data->n_texture);
	}
	if (data->s_texture)
	{
		if (data->s_texture->pont)
			mlx_destroy_image (data->mlx, data->s_texture->pont);
		free (data->s_texture);
	}
	if (data->w_texture)
	{
		if (data->w_texture->pont)
			mlx_destroy_image (data->mlx, data->w_texture->pont);
		free (data->w_texture);
	}
	if (data->e_texture)
	{
		if (data->e_texture->pont)
			mlx_destroy_image (data->mlx, data->e_texture->pont);
		free (data->e_texture);
	}
}

void	destroy_rays(t_data *data)
{
	int	index;

	index = 0;
	while (index < NUM_RAYS)
	{
		free(data->rays[index].render);
		free(data->rays[index].hrz);
		free(data->rays[index].vert);
		index++;
	}
}
