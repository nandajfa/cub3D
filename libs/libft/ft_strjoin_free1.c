/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:02:51 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 19:17:20 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free1(char *s1, char const *s2, size_t size2)
{
	unsigned int	size;
	unsigned int	size1;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size = size1 + size2 + 1;
	new = (char *)ft_calloc(sizeof(char), size);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, size1 + 1);
	ft_strlcpy(new + size1, s2, size2 + 1);
	ft_strdel(&s1);
	return (new);
}
