/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:30:23 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:42 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*ptr;
	unsigned char	vle;

	ptr = (unsigned char *)pointer;
	vle = (unsigned char)value;
	while (count != 0)
	{
		*ptr++ = vle;
		count --;
	}
	return (pointer);
}
