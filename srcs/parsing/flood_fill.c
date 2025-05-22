/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:04:07 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/22 19:32:34 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	fill(char **tab, t_point size, t_point current, char to_fill)
// {
// 	if (current.y < 0 || current.y >= size.y || current.x < 0
// 		|| current.x >= size.x || tab[current.y][current.x] != to_fill)
// 		return ;
// 	tab[current.y][current.x] = 'F';
// 	fill(tab, size, (t_point){current.x - 1, current.y}, to_fill);
// 	fill(tab, size, (t_point){current.x + 1, current.y}, to_fill);
// 	fill(tab, size, (t_point){current.x, current.y - 1}, to_fill);
// 	fill(tab, size, (t_point){current.x, current.y + 1}, to_fill);
// }

// void	flood_fill(char **tab, t_point size, t_point begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }

