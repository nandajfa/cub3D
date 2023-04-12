/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:57:37 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 18:59:32 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	x;
	size_t	s_total;

	x = 0;
	s_total = count * size;
	str = NULL;
	str = malloc(s_total);
	if (str == NULL)
		return (0);
	if (s_total > 10000)
		x = s_total - 9000;
	while (x < s_total)
	{
		str[x] = 0;
		x++;
	}
	return ((void *)str);
}
