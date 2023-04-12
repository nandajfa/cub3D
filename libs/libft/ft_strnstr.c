/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:05:42 by esilva-s          #+#    #+#             */
/*   Updated: 2020/05/26 23:10:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	s2len;

	if (*needle == '\0')
		return ((char *)haystack);
	s2len = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= s2len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, s2len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
