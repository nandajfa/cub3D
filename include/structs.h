/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:10:56 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 17:35:23 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "defines.h"

typedef struct s_image
{
	char	*patch;
	void	*pont;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data_img;
}	t_image;

typedef struct s_map
{
	char	*patch;
	char	**map_matrix;
	int		nb_lines;
	int		nb_columns;
	int		height_px;
	int		width_px;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*str_floor;
	char	*str_sky;
	int		color_floor;
	int		color_sky;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	turn_speed;
	double	angle;
}	t_player;

typedef struct s_render
{
	double	proj_wall_height;
	int		wall_bottom_pixel;
	int		wall_top_pixel;
	int		wall_strip_height;
}	t_render;

typedef struct s_inter
{
	int		found_wall;
	double	wall_x;
	double	wall_y;
	double	step_x;
	double	step_y;
	double	distance;
}	t_inter;

typedef struct s_ray
{
	double		ray_angle;
	t_inter		*hrz;
	t_inter		*vert;
	double		distance;
	int			vertical_wall;
	t_render	*render;
	double		is_facing_down;
	double		is_facing_up;
	double		is_facing_right;
	double		is_facing_left;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			close_game;
	double		dist_proj_plane;
	t_map		*map;
	t_image		*n_texture;
	t_image		*s_texture;
	t_image		*e_texture;
	t_image		*w_texture;
	t_image		*image;
	t_player	*player;
	t_ray		rays[NUM_RAYS];
}	t_data;

#endif /* CUB3D_H */
