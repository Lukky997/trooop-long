/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:52:07 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/17 12:49:29 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	compteur;

	compteur = 0;
	if (!str)
		return (0);
	while (str[compteur])
		compteur++;
	return (compteur);
}
