/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blopez-f <blopez-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:51:18 by blopez-f          #+#    #+#             */
/*   Updated: 2022/10/24 22:56:58 by blopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*aux_big;
	size_t	aux_len;

	if (ft_strlen(big) < ft_strlen(little))
		return (0);
	aux_big = (char*)big;
	aux_len = 0;
	while (ft_strncmp(aux_big, little, len) == 0 && aux_len < len && *aux_big)
	{
		aux_big++;
		aux_len++;
	}
	if (ft_strncmp(aux_big, little, len) > 0)
		return(aux_big);
	return (0);
}
