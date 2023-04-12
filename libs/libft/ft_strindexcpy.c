/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindexcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:01:12 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 19:14:40 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strindexcpy(char **save, char *str, size_t index)
{
	size_t			count;
	char			*dst;
	size_t			size;

	count = 0;
	size = ft_strlen(str);
	dst = (char *)ft_calloc(sizeof(char), (size - (index)) + 1);
	while (count < size && index < size)
	{
		dst[count] = str[index];
		index++;
		count++;
	}
	dst[count] = '\0';
	*save = dst;
	return (dst);
}
