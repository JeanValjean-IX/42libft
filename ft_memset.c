/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blopez-f <blopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:24:18 by blopez-f          #+#    #+#             */
/*   Updated: 2022/09/30 13:04:37 by blopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void  *ft_memset(void *dest, int val, size_t len)
{
  unsigned char *ptr = dest;
  while (len-- > 0)
    *ptr++ = val;
  return (dest);
}
