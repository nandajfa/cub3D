/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:45:25 by esilva-s          #+#    #+#             */
/*   Updated: 2020/05/26 23:00:26 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*a;
	unsigned const char	*b;

	a = dst;
	b = src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (a[i] == (unsigned char)c)
			return (&a[i + 1]);
		i++;
	}
	return (NULL);
}
