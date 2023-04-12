/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:55:45 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_loop(t_data **data)
{
	render(*data);
	return (0);
}

static int	start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Error\nNo graphical interface.\n");
		destroy(data);
		exit(1);
	}
	if (load_textures(data))
	{
		destroy(data);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!data->win)
	{
		printf("Error\nNo graphical interface.\n");
		destroy(data);
		exit(1);
	}
	data->image->pont = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image->patch = mlx_get_data_addr(data->image->pont, &data->image->bpp,
			&data->image->size_line, &data->image->endian);
	return (0);
}

static int	check_args(int argc, char **argv)
{
	int		len;
	char	*str;

	if (argc < 2)
	{
		printf("Error\nWrong numbers of arguments\n");
		return (1);
	}
	else
	{
		len = 0;
		str = ft_strrchr(argv[1], '.');
		if (str)
		{
			len = ft_strlen(str);
			if (!ft_memcmp(str, ".cub", len))
				return (0);
		}
		printf("Error\nInvalid map extension. Use .cub\n");
		return (1);
	}
	return (0);
}

static int	close_game(t_data *data)
{
	mlx_loop_end(data->mlx);
	destroy(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (0);
	data = init(argv[1]);
	if (build_data(data))
	{
		destroy(data);
		return (0);
	}
	get_player(data);
	if (start_mlx(data))
		return (0);
	mlx_hook(data->win, KEY_PRESS, 1L << 0, key_hook, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, close_game, data);
	mlx_loop_hook(data->mlx, &render_loop, &data);
	mlx_loop(data->mlx);
	destroy(data);
	return (0);
}
