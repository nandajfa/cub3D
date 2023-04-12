/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_refined_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:35:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 19:08:47 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_node(char *node)
{
	int	count;
	int	size;

	count = 0;
	size = ft_strlen(node);
	if (size < 0 || size > 3)
		return (1);
	while (count < size)
	{
		if (!ft_isdigit(node[count]))
			return (1);
		count++;
	}
	return (0);
}

static int	check_color(char *color)
{
	char	**rgb_color;
	int		index;
	int		nb;

	index = 0;
	rgb_color = ft_split(color, ',');
	if (ft_matrix_strlen(rgb_color) != 3)
	{
		ft_matrix_strdel(rgb_color);
		return (1);
	}
	while (index < 3)
	{
		nb = ft_atoi(rgb_color[index]);
		if (!(nb > -1 && nb < 256) || check_node(rgb_color[index]))
		{
			ft_matrix_strdel(rgb_color);
			return (1);
		}
		index++;
	}
	ft_matrix_strdel(rgb_color);
	return (0);
}

int	check_refined_color(t_data *data)
{
	if (check_color(data->map->str_sky))
	{
		printf("Error\nSky color is wrong\n");
		return (1);
	}
	if (check_color(data->map->str_floor))
	{
		printf("Error\nThe floor color is wrong\n");
		return (1);
	}
	return (0);
}
