/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blopez-f <blopez-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:03:14 by blopez-f          #+#    #+#             */
/*   Updated: 2022/11/27 22:14:51 by blopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux_buffer;
	size_t	aux_start;
	size_t	aux_end;

	if (!s1 || !set)
		return (0);
	aux_start = 0;
	aux_end = ft_strlen(s1) - 1;
	while (s1[aux_start] && ft_strchr(set, s1[aux_start]))
		aux_start++;
	if (aux_start >= aux_end)
		return (ft_strdup(""));
	while (s1[aux_end] && ft_strchr(set, s1[aux_end]))
		aux_end--;
	aux_buffer = ft_calloc(sizeof(char), (aux_end - aux_start) + 2);
	if (!aux_buffer)
		return (0);
	ft_memcpy(aux_buffer, s1 + aux_start, aux_end - aux_start + 1);
	return (aux_buffer);
}
