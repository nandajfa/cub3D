/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:10:03 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:16:59 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_image	*load_xpm(t_data *data, char *path)
{
	t_image	*result;
	int		w;
	int		h;

	result = NULL;
	result = ft_calloc(sizeof(t_image), 1);
	result->pont = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (result->pont == NULL)
	{
		printf("Error\ntexture file is wrong\n");
		free(result);
		return (NULL);
	}
	result->data_img = mlx_get_data_addr(result->pont,
			&result->bpp, &result->size_line, &result->endian);
	if (result->data_img == NULL)
	{
		printf("Error\nMlx data image error\n");
		mlx_destroy_image(data->mlx, result->pont);
		free(result);
		return (NULL);
	}
	return (result);
}

int	load_textures(t_data *data)
{
	data->n_texture = load_xpm(data, data->map->no_path);
	if (data->n_texture == NULL)
		return (1);
	data->s_texture = load_xpm(data, data->map->so_path);
	if (data->s_texture == NULL)
		return (1);
	data->e_texture = load_xpm(data, data->map->ea_path);
	if (data->e_texture == NULL)
		return (1);
	data->w_texture = load_xpm(data, data->map->we_path);
	if (data->w_texture == NULL)
		return (1);
	return (0);
}
