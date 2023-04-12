/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:20:51 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 18:57:23 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_n(int n)
{
	int			len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;

	size = size_n(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n > 9)
	{
		str[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	str[size - 1] = n + '0';
	return (str);
}
