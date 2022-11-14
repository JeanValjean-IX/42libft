/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blopez-f <blopez-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:12:25 by blopez-f          #+#    #+#             */
/*   Updated: 2022/11/14 23:17:21 by blopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_clean(char **buffer, size_t size)
{
	size_t	aux_pos;

	aux_pos = 0;
	while (aux_pos < size)
	{
		free(buffer[aux_pos]);
		aux_pos++;
	}
	free(buffer);
	return (NULL);
}

char	*ft_getword(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	pos;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_bzero(word, end - start + 1);
	pos = 0;
	while (start < end)
	{
		word[pos] = s[start];
		pos++;
		start++;
	}
	return (word);
}

size_t	ft_counter(const char *s, const char c)
{
	size_t	count;
	size_t	found;

	count = 0;
	found = 1;
	while (*s)
	{
		if (*s != c && found == 1)
		{
			found = 0;
			count++;
		}
		else if (*s == c)
			found = 1;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	pos_s;
	size_t	pos_buffer;
	size_t	found;	
	size_t	start;

	buffer = (char **)malloc((ft_counter(s, c) + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	pos_s = 0;
	pos_buffer = 0;
	found = 1;
	start = 0;
	while (pos_s <= ft_strlen(s) && ft_strlen(s) > 0)
	{
		if (s[pos_s] != c && found == 1)
		{
			found = 0;
			start = pos_s;
		}
		else if ((s[pos_s] == c || pos_s == ft_strlen(s)) && found == 0)
		{
			found = 1;
			buffer[pos_buffer] = ft_getword(s, start, pos_s);
			//buffer[pos_buffer] = ft_substr(s, start, (pos_s - start));
			if (buffer[pos_buffer] == NULL)
				return (ft_clean(buffer, pos_buffer));
			pos_buffer++;
		}
		pos_s++;
	}
	buffer[pos_s] = 0;
	return (buffer);
}
