/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:04:57 by esilva-s          #+#    #+#             */
/*   Updated: 2020/01/29 15:04:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp2;

	i = 0;
	tmp = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while ((tmp[i] != '\0' || tmp2[i] != '\0') && i < n)
	{
		if (tmp[i] != tmp2[i])
			return ((unsigned int)tmp[i] - (unsigned int)tmp2[i]);
		i++;
	}
	return (0);
}
