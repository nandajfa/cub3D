/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:24:48 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 18:58:16 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_start(const char *s, const char *set)
{
	int		size;
	int		count;

	count = 0;
	size = ft_strlen(s);
	while (count < size)
	{
		if (ft_strchr(set, s[count]) == 0)
			break ;
		count++;
	}
	return (count);
}

static int	in_end(const char *s, const char *set)
{
	int		size;
	int		count;

	count = 0;
	size = ft_strlen(s);
	while (count < size)
	{
		if (ft_strchr(set, s[size - count - 1]) == 0)
			break ;
		count++;
	}
	return (size - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = in_start(s1, set);
	end = in_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1 + start, end - start + 1);
	return (new);
}
