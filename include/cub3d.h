/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:33:45 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include "defines.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libs/libft/libft.h"

/* init.c */
t_data	*init(char *patch);

/* ---- init_aux.c */
void	init_rays(t_data *data);

/* destroy.c */
int		destroy(t_data *data);

/* ---- destroy_aux.c*/
void	destroy_rays(t_data *data);
void	destroy_texture(t_data *data);

/* build_data.c */
int		build_data(t_data *data);

/* ---- build_tools.c */
int		is_line_map(char *element);
int		convert_hex(char *color);

/* ---- read_file.c */
char	**read_file(t_data *data);

/* ---- check_contents_file.c */
int		check_contents_file(char **file);

/* ---- extract_contents.c */
char	*extract_content(char **file, char *key, int i);
void	extract_map(t_data *data, char **file);

/* ---- ---- extract_contents_aux.c */
void	extract_map(t_data *data, char **file);

/* ---- check_refined_texture.c*/
int		check_refined_texture(t_data *data);

/* ---- check_refined_color.c */
int		check_refined_color(t_data *data);

/* ---- check_refined_map.c */
int		check_refined_map(t_data *data);

/* ---- ---- check_refined_map_aux.c */
int		check_walls(t_map *map);
int		check_player(char **map);

/* load_texture.c */
int		load_textures(t_data *data);

/* offset.c */
int		calculate_off_y(int y, double wall_height);
int		calculate_off_x(t_ray *ray);

int		render_loop(t_data **data);

/* draw_wall.c */
void	draw_wall(t_data *data, t_ray *ray, int x);

/* moviments.c */
void	moviments_up_down(t_data *data, int key);
void	moviments_left_right(t_data *data, int key);
void	rotate(t_data *data, int key);
int		check_player_position(t_data *data, double x, double y);

/* key_hook.c*/
int		key_hook(int key, t_data *data);

/* render.c */
void	draw_pixel_color(t_image *img, int x, int y, int color);
int		copycolor(t_image *img, int x, int y);
void	render(t_data *data);

/* get_player*/
void	get_player(t_data *data);

/* intersection.c */
int		wall_collision(double x, double y, t_data *data);
void	vertical_intersection(t_data *data, t_ray *ray);
void	horizontal_intersection(t_data *data, t_ray *ray);

/* raycasting.c */
void	raycasting(t_data *data);

/* project_rays.c */
void	project_rays(t_data *data, t_ray *ray);

/* render_3d.c */
void	render_3d_projected_walls(t_data *data);

/* ray_tools.c */
double	normalize_angle(double angle);

#endif /* CUB3D_H */
