/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:17:30 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/24 15:12:36 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->mlx_window = mlx_new_window(data->mlx, 1920, 1080, "TROP LONG");
	if (!data->mlx_window)
		return (0);
	data->move = 0;
	render_map(data);
	render_element(data);
	mlx_key_hook(data->mlx_window, handle_keypress, &data);
	mlx_loop(data->mlx);
	return (1);
}

void	valid_map(t_data *data)
{
	int	P;
	int	E;

	P = check_map_element(data, 'P');
	data->nb_c = check_map_element(data, 'C');
	E = check_map_element(data, 'E');
	if (!is_map_rectangular(data->map))
		exit_error(1);
	if (!is_wall_closed(data->map))
		exit_error(1);
	if (!check_char_map(data->map))
		exit_error(1);
	if (P != 1 || data->nb_c < 1 || E != 1)
		exit_error(1);
	open_window(data);
}

void	set_map_size(t_data *data)
{
	while(data->map[data->map_height])
		data->map_height++;
	if (data->map_height > 0)
		data->map_width = ft_strlen(data->map[0]);
	else
		data->map_width = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 2 || (!env) || (!is_ber_file(argv[1])))
		exit_error(1);
	make_map_2d(&data, argv[1]);
	if (!data.map)
		exit_error(1);
	set_map_size(&data);
	valid_map(&data);
	ft_printf("%s\n", data.map[1]);
	free_map(data.map);
	return (0);
}
