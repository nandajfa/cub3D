/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:44:01 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/05 18:03:02 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix_strdup(char **matrix)
{
	char	**result;
	int		size;
	int		index;

	index = 0;
	if (matrix == NULL)
		return (NULL);
	size = ft_matrix_strlen(matrix);
	result = ft_calloc(sizeof(char *), size);
	while (index < size)
	{
		result[index] = ft_strdup(matrix[index]);
		index++;
	}
	return (result);
}
