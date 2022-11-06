/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blopez-f <blopez-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:12:25 by blopez-f          #+#    #+#             */
/*   Updated: 2022/11/06 22:08:58 by blopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_clean(char **s, const size_t loop)
{
	(void)s;
	(void)loop;
	return (0);
}

char	*ft_memfill(const char *s, const char c, const size_t counter)
{
	char *aux_s;
	size_t	aux_s_size;
	size_t	aux_loop;

	aux_s = (char *)s;
	aux_loop = 0;
	while (aux_loop < counter)
	{
		aux_s = ft_strchr(aux_s, c);
		aux_loop++;
	}

	//capturar palabra
	
	return ();
}

size_t	ft_counter_words(const char *s, char c)
{
	size_t	aux_s_size;
	size_t	aux_loop;
	size_t	aux_counter;

	aux_s_size = ft_strlen(s);
	if (aux_s_size > 0 && !ft_strchr(s, c))
		return (1);
	aux_counter = 1;
	aux_loop = 0;
	while (s[aux_loop])
	{
		if (s[aux_loop] == c && s[aux_loop + 1])
			aux_counter++;
		aux_loop++;
	}
	return (aux_counter);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	aux_counter;
	size_t	aux_loop;
	int		flag_error;

	if (!s)
		return (0);
	aux_counter = ft_counter_words(s, c);
	buffer = (char **)malloc(aux_counter * sizeof(char *));
	if (buffer == NULL)
		return (0);
	aux_loop = 0;
	while (aux_loop <= aux_counter && flag_error == 0)
	{
		buffer[aux_loop] = ft_memfill(s, c, aux_counter);
		if (!buffer[aux_loop])
			flag_error = 1;
		aux_loop++;
	}
	return (buffer);
}
