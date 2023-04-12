/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:57:15 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 19:11:41 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(const char *c)
{
	if (*c == ' ' || *c == '\n' || *c == '\t')
		return (1);
	if (*c == '\v' || *c == '\f' || *c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		negative;

	negative = 1;
	result = 0;
	while (ft_space(str))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	result = result * negative;
	return (result);
}
