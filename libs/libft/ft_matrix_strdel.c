/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_strdel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:43:32 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/05 18:02:56 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_strdel(char **matrix)
{
	int	index;
	int	size;

	index = 0;
	if (matrix == NULL)
		return ;
	size = ft_matrix_strlen(matrix);
	while (index < size)
	{
		ft_strdel(&matrix[index]);
		index++;
	}
	free(matrix);
}
