/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:44:33 by lgoras            #+#    #+#             */
/*   Updated: 2025/06/02 14:55:19 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*read_map_file(const char *filename)
{
	int		fd;
	char	*line;
	char	*result;
	char	*temp;

	result = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Error : Failed to open map file\n");
	line = get_next_line(fd);
	while (line)
	{
		if (!result)
			result = ft_strdup(line);
		else
		{
			temp = ft_strjoin(result, line);
			free(result);
			result = temp;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (result);
}

void	make_map_2d(t_data *data, const char *filename)
{
	char	*result;

	result = read_map_file(filename);
	if (!result || !is_map_clean(result))
		exit_error("Error : Map contains empty lines or invalid format\n");
	data->map = ft_split(result, '\n');
	free(result);
	if (!data->map)
		exit_error("Error : Memory allocation for map failed\n");
}

int	is_ber_file(const char *filename)
{
	const char	*ext;

	if (!filename)
		return (0);
	ext = ft_strchr(filename, '.');
	if (!ext)
		return (0);
	if (ft_strncmp(ext, ".ber", 5) == 0)
		return (1);
	return (0);
}
