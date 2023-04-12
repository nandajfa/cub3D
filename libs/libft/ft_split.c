/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:22:25 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 19:16:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_total(char const *s, char c)
{
	unsigned int	count;
	unsigned int	total;

	count = 0;
	total = 0;
	if (!s[count])
		return (0);
	while (s[count] && s[count] == c)
		count++;
	while (s[count])
	{
		if (s[count] == c)
		{
			total++;
			while (s[count] && s[count] == c)
				count++;
			continue ;
		}
		count++;
	}
	if (s[count - 1] != c)
		total++;
	return (total);
}

static void	next_word(char **word, unsigned int *size_word, char c)
{
	unsigned int	count;

	count = 0;
	*word += *size_word;
	*size_word = 0;
	while (**word && **word == c)
		(*word)++;
	while ((*word)[count])
	{
		if ((*word)[count] == c)
			return ;
		(*size_word)++;
		count++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	char			*word;
	unsigned int	size_word;
	unsigned int	size_total;
	unsigned int	count;

	count = 0;
	size_word = 0;
	word = (char *)s;
	size_total = count_total(s, c);
	result = (char **)malloc(sizeof(char *) * (size_total + 1));
	if (!s || result == NULL)
		return (NULL);
	while (count < size_total)
	{
		next_word(&word, &size_word, c);
		result[count] = (char *)malloc(sizeof(char) * (size_word + 1));
		if (result == NULL)
			return (NULL);
		ft_strlcpy(result[count], word, size_word + 1);
		count++;
	}
	result[count] = 0;
	return (result);
}
