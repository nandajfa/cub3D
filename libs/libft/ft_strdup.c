/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:06:37 by esilva-s          #+#    #+#             */
/*   Updated: 2020/05/26 15:52:04 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		x;
	int		size;

	size = 0;
	while (s1[size])
		size++;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!(dest))
		return (NULL);
	x = 0;
	while (s1[x])
	{
		dest[x] = s1[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
