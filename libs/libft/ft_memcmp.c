/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:58:34 by esilva-s          #+#    #+#             */
/*   Updated: 2020/03/25 13:12:01 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	count;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (!(str1[count] == str2[count]))
			return ((int)(str1[count] - str2[count]));
		count++;
	}
	return ('\0');
}
