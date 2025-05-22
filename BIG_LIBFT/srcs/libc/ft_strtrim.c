/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:22:15 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:42 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

static int	check_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new_str;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	if (start == end)
		return (ft_strdup(""));
	while (s1[start] && check_set(s1[start], set))
		start++;
	while (start < end && check_set(s1[end - 1], set))
		end--;
	new_str = malloc(sizeof(char) * ((end - start) + 1));
	if (!new_str || !s1)
		return (NULL);
	while (start < end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	return (new_str);
}
