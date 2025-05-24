/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:25:27 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/24 15:18:13 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_data *data, int x, int y)
{
	char	cell;

	if (y < 0 || y >= data->map_height || x < 0 || x >= data->map_width)
		return (0);
	cell = data->map[y][x];
	if (cell == '1')
		return (0);
	if (cell == 'E' && data->nb_c > 0)
		return (0);
	return (1);
}

void	move_player(t_data *data, int dx, int dy, int img_dir)
{
	ft_printf("Move player called: dx=%d dy=%d\n", dx, dy);
	int		x;
	int		y;
	char	cell;

	x = data->coord.x + dx;
	y = data->coord.y + dy;
	if (!check_move(data, x, y))
		return ;
	cell = data->map[y][x];
	if (cell == 'C')
		data->nb_c--;
	if (cell == 'E' && data->nb_c == 0)
		exit(0);
	data->map[data->coord.y][data->coord.x] = '0';
	data->coord.x = x;
	data->coord.y = y;
	data->map[y][x] = 'P';
	ft_printf("Current pos: (%d, %d)\n", data->coord.x, data->coord.y);
	data->move++;
	render_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[img_dir], x
		* 32, y * 32);
	render_element(data);
	ft_printf("Move : %d\n", data->move);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit(0);
	else if (keycode == XK_w)
		move_player(data, 0, -1, 3);
	else if (keycode == XK_a)
		move_player(data, -1, 0, 1);
	else if (keycode == XK_s)
		move_player(data, 0, 1, 2);
	else if (keycode == XK_d)
		move_player(data, 1, 0, 0);
	return (0);
}