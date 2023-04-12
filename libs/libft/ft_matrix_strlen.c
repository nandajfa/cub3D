/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:49:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/05 18:03:43 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrix_strlen(char **matrix)
{
	int	len;

	len = 0;
	if (matrix == NULL)
		return (-1);
	while (matrix[len] != 0)
		len++;
	return (len);
}
