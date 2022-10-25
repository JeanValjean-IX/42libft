/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blopez-f <blopez-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:51:18 by blopez-f          #+#    #+#             */
/*   Updated: 2022/10/25 21:37:05 by blopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	aux_len;
	char	*aux_big_01;
	char	*aux_big_02;
	char	*aux_little;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	aux_big_01 = (char *)big;
	aux_len = 0;
	while (*aux_big_01 != '\0' && aux_len < len - 1
		&& ft_strlen(little) <= len)
	{
		aux_little = (char *)little;
		aux_big_02 = aux_big_01;
		while (*aux_big_02 == *aux_little && (size_t)(aux_big_02 - big) < len)
		{
			aux_big_02++;
			aux_little++;
			if (*aux_little == '\0')
				return (aux_big_01);
		}
		aux_big_01++;
		aux_len++;
	}
	return (0);
}
