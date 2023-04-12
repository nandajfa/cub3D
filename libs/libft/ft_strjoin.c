/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:23:37 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 18:57:30 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	unsigned int	size1;
	unsigned int	size2;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	new = NULL;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	size = size1 + size2 + 1;
	new = malloc(sizeof(char) * size);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, size1 + 1);
	ft_strlcat(new + size1, s2, size2 + 1);
	return (new);
}
