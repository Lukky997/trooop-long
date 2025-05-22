/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:46:31 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:42 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	index = (unsigned int)start;
	if (!s)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[start] && i < len)
		ptr[i++] = s[index++];
	ptr[i] = '\0';
	return (ptr);
}
