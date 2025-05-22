/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:35:57 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:42 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

char	*ft_strchr(const char *str, int chr)
{
	size_t	i;

	i = 0;
	if (*str == '\0' && chr == '\0')
		return ((char *)str);
	if (*str == '\0')
		return (NULL);
	while (i <= ft_strlen(str))
	{
		if (str[i] == (char)chr)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
