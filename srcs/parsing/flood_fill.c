/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:04:07 by lgoras            #+#    #+#             */
/*   Updated: 2025/06/02 14:55:24 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

char	**dup_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	replace_exit_if_needed(char **map, int nb_c)
{
	int i;
	int j;

	if (nb_c <= 0)
		return ;
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'E')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	check_path(t_data *data)
{
	char **map_copy;
	int i;
	int j;

	map_copy = dup_map(data->map);
	if (!map_copy)
		exit_error("Error : Map duplication failed\n");
	replace_exit_if_needed(map_copy, data->nb_c);
	fill(map_copy, data->coord.x, data->coord.y);
	i = 0;
	while(map_copy[i])
	{
		j = 0;
		while(map_copy[i][j])
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_map(map_copy);
				exit_error("Error : Unreachable collectible or exit\n");
			}
			j++;
		}
		i++;
	}
	free_map(map_copy);
}
