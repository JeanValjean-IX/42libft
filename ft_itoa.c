/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blopez-f <blopez-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:39:48 by blopez-f          #+#    #+#             */
/*   Updated: 2022/11/20 21:49:33 by blopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_istrlen(const int n)
{
	size_t	size;
	int		num;

	num = n;
	size = 0;
	if (num < 0)
	{
		num = -num;
		size = 1;
	}
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		aux_n;
	size_t	size;
	size_t	pos;
	size_t	aux_pos;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	size = ft_istrlen(n);
	buffer = (char *)ft_calloc(sizeof(char), size + 1);
	if (buffer == NULL)
		return (NULL);
	pos = 0;
	aux_n = n;
	if (n < 0)
	{
		buffer[0] = '-';
		aux_n = -n;
		pos = 1;
	}
	while (pos < size)
	{
		aux_pos = size - pos - 1;
		if (n < 0)
			aux_pos++;
		buffer[aux_pos] = '0' + aux_n % 10;
		aux_n = aux_n / 10;
		pos++;
	}
	return (buffer);
}
