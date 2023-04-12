/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:30:48 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 23:39:37 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extraction(char *line, int size_key)
{
	int		index;
	int		size;
	char	*result;

	index = 0;
	size = ft_strlen(line);
	result = NULL;
	result = ft_calloc(sizeof(char), size - size_key + 2);
	while (index < size -1 && index + size_key < size)
	{
		result[index] = line[index + size_key];
		index++;
	}
	result[index] = '\0';
	return (result);
}

static int	search_line(char *key, char *line)
{
	size_t	count;
	size_t	size;

	count = 0;
	size = ft_strlen(key);
	while (key[count] == line[count] && count < size)
			count++;
	if (count == size)
		return (1);
	return (0);
}

char	*extract_content(char **file, char *key, int i)
{
	int		index;
	size_t	size;
	char	*result;

	index = 0;
	size = ft_strlen(key);
	result = NULL;
	while (file[index] != NULL)
	{
		i = size;
		if (!(size + 1 < ft_strlen(file[index])))
		{
			index++;
			continue ;
		}
		if (search_line(key, file[index]))
		{
			while (file[index][i] == ' ')
				i++;
			result = extraction(file[index], i);
			break ;
		}
		index++;
	}
	return (result);
}
