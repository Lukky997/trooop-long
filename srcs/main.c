/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:17:30 by lgoras            #+#    #+#             */
/*   Updated: 2025/06/02 15:44:35 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->mlx_window = mlx_new_window(data->mlx, (data->map_width * 32),
			(data->map_height * 32), "TROP LONG");
	if (!data->mlx_window)
		return (0);
	data->move = 0;
	render_map(data);
	render_element(data);
	mlx_hook(data->mlx_window, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->mlx_window, 17, 0, &close_window, data);
	mlx_loop(data->mlx);
	return (1);
}

static void	valid_map(t_data *data)
{
	int	nb_p;
	int	nb_e;

	nb_p = check_map_element(data, 'P');
	data->nb_c = check_map_element(data, 'C');
	nb_e = check_map_element(data, 'E');
	if (!is_map_rectangular(data->map))
		exit_error("Error : Map is not rectangular\n", data);
	if (!is_wall_closed(data->map))
		exit_error("Error : Map is not closed by walls\n", data);
	if (!check_char_map(data->map))
		exit_error("Error : Map contains invalid characters\n", data);
	if (nb_p != 1 || data->nb_c < 1 || nb_e != 1)
		exit_error("Error : Map must contain 1 'P', 1 'C', and 1 'E'\n", data);
	check_path(data);
	if (!open_window(data))
		exit_error("Error: Could not open window or initialize MLX\n", data);
}

void	set_map_size(t_data *data)
{
	data->map_height = 0;
	while (data->map[data->map_height])
		data->map_height++;
	if (data->map_height > 0)
		data->map_width = ft_strlen(data->map[0]);
	else
		data->map_width = 0;
	if (data->map_width > MAX_MAP_WIDTH || data->map_height > MAX_MAP_HEIGHT)
		exit_error("Error : Map is too large\n", data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2 || (!env) || (!is_ber_file(argv[1])))
		exit_error("Error: Invalid arguments or .ber file.\n", &data);
	make_map_2d(&data, argv[1]);
	if (!data.map)
		exit_error("Error : Map could not be created\n", &data);
	set_map_size(&data);
	valid_map(&data);
	ft_printf("%s\n", data.map[1]);
	free_map(data.map);
	return (0);
}
