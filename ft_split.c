/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blopez-f <blopez-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:12:25 by blopez-f          #+#    #+#             */
/*   Updated: 2022/11/18 23:39:46 by blopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_count_words(const char *s, char c)
{
	size_t	size;
	size_t	position;

	size = 0;
	position = 0;
	while (s[position])
	{
		while (s[position] == c)
			position++;
		if (s[position])
		{
			while (s[position] && s[position] != c)
				position++;
			size++;
		}
	}
	return (size);
}

size_t	ft_wlen(char const *s, char c, size_t position)
{
	size_t	size;

	size = 0;
	while (s[position] && s[position] != c)
	{
		position++;
		size++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	buffer = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			buffer[j] = (char *)malloc((ft_wlen(s, c, i) + 1) * sizeof(char));
			ft_bzero(buffer[j], (ft_wlen(s, c, i) + 1));
			k = 0;
			while (s[i] && s[i] != c)
			{
				buffer[j][k] = s[i];
				i++;
				k++;
			}
			j++;
		}
	}
	buffer[j] = 0;
	return (buffer);
}
