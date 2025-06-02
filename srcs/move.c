/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:25:27 by lgoras            #+#    #+#             */
/*   Updated: 2025/06/02 15:45:04 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	replace_exit_with_open(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window,
					data->img[8], j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}

static int	check_move(t_data *data, int x, int y)
{
	char	cell;

	cell = data->map[y][x];
	if (cell == '1')
		return (0);
	if (cell == 'E' && data->nb_c > 0)
		return (0);
	return (1);
}

static void	move_player(t_data *data, int dx, int dy, int img_dir)
{
	int	x;
	int	y;

	x = data->coord.x + dx;
	y = data->coord.y + dy;
	if (!check_move(data, x, y))
		return ;
	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		data->nb_c--;
		if (data->nb_c == 0)
			replace_exit_with_open(data);
	}
	if (data->map[y][x] == 'E' && data->nb_c == 0)
		winner(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[9],
		data->coord.x * 32, data->coord.y * 32);
	data->coord.x = x;
	data->coord.y = y;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[img_dir], x
		* 32, y * 32);
	data->move++;
	ft_printf("Move %d:\n", data->move);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	else if (keycode == W)
		move_player(data, 0, -1, 3);
	else if (keycode == A)
		move_player(data, -1, 0, 1);
	else if (keycode == S)
		move_player(data, 0, 1, 0);
	else if (keycode == D)
		move_player(data, 1, 0, 2);
	return (0);
}
