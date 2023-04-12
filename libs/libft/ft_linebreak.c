/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linebreak.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:57:45 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 19:10:04 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_linebreak(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}
