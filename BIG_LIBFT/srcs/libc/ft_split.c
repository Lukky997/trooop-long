/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:24:23 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/19 18:03:28 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	compteur;
	size_t	index;

	compteur = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == '\0'))
			compteur++;
		index++;
	}
	return (compteur);
}

static size_t	len_str(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s++)
		i++;
	return (i);
}

static char	**free_split(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static void	skip_delimiters(char const **s, char c)
{
	while (**s && **s == c)
		(*s)++;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	word_index;
	size_t	letter_index;

	word_index = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	skip_delimiters(&s, c);
	while (*s)
	{
		letter_index = 0;
		tab[word_index] = malloc(sizeof(char) * (len_str(s, c) + 1));
		if (!tab[word_index])
			return (free_split(tab));
		while (*s && *s != c)
			tab[word_index][letter_index++] = *s++;
		skip_delimiters(&s, c);
		tab[word_index][letter_index] = '\0';
		word_index++;
	}
	tab[word_index] = NULL;
	return (tab);
}
