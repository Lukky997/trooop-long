/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:47:29 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:42 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

void	*ft_calloc(size_t element_count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (element_count == 0 || size == 0)
		return (malloc(0));
	ptr = (void *)malloc(element_count * size);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	while (i < (element_count * size))
	{
		*(unsigned char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
