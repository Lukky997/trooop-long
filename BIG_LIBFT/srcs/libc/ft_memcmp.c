/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:38:12 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:42 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

int	ft_memcmp(const void *ptr_1, const void *ptr_2, size_t size)
{
	unsigned char	*memblock_1;
	unsigned char	*memblock_2;
	size_t			i;

	i = 0;
	memblock_1 = (unsigned char *)ptr_1;
	memblock_2 = (unsigned char *)ptr_2;
	while (i < size)
	{
		if (memblock_1[i] != memblock_2[i])
			return (memblock_1[i] - memblock_2[i]);
		i++;
	}
	return (0);
}
