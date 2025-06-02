/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:03:24 by lgoras            #+#    #+#             */
/*   Updated: 2025/06/02 12:54:28 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_clean(char *map)
{
	int	i;

	if (!map || map[0] == '\n')
	{
		free(map);
		return (0);
	}
	i = 0;
	while (map[i])
	{
		if ((map[i] == '\n' && map[i + 1] == '\n') || (map[i] == '\n' && map[i
					+ 1] == ' ') || map[i] == ' ')
		{
			free(map);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_map_rectangular(char **map)
{
	int		i;
	size_t	width;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (width > MAX_MAP_WIDTH)
		return(0);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width || ft_strlen(map[i]) > MAX_MAP_WIDTH)
			return (0);
		i++;
	}
	if (i > MAX_MAP_HEIGHT)
		return (0);
	return (1);
}

int	is_wall_closed(char **map)
{
	int	i;
	int	width;
	int	height;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < (height - 1))
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_element(t_data *data, char element)
{
	int	i;
	int	j;

	i = 0;
	data->count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == element)
				data->count++;
			if (data->map[i][j] == 'P')
			{
				data->coord.x = j;
				data->coord.y = i;
			}
			j++;
		}
		i++;
	}
	return (data->count);
}

int	check_char_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
