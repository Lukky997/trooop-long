/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:17:30 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/22 20:02:19 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_data *data)
{
	int	P;
	int	C;
	int	E;

	P = check_map_element(data, 'P');
	C = check_map_element(data, 'C');
	E = check_map_element(data, 'E');
	if (!is_map_rectangular(data->map))
		exit_error(1);
	if (!is_wall_closed(data->map))
		exit_error(1);
	if (!check_char_map(data->map))
		exit_error(1);
	if (P != 1 || C < 1 || E != 1)
		exit_error(1);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 2 && (!env))
		exit_error(1);
	make_map_2d(&data, argv[1]);
	if (!data.map)
		exit_error(1);
	valid_map(&data);
	ft_printf("%s\n", data.map[1]);
	free_map(data.map);
	return (0);
}
