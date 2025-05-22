/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:24:51 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:42 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

void	*ft_memchr(const void *mem_block, int chr, size_t size)
{
	unsigned char	searched_char;
	unsigned char	*mem;
	size_t			i;

	i = 0;
	searched_char = (int)chr;
	mem = (unsigned char *)mem_block;
	while (i < size)
	{
		if (mem[i] == searched_char)
			return ((void *)mem + i);
		i++;
	}
	return (NULL);
}
