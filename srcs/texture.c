/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:16:36 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/24 14:52:26 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture(t_data *data)
{
	data->img[0] = mlx_xpm_file_to_image(data->mlx,
			"srcs/textures/bombardiro1.xpm", &data->img_width,
			&data->img_height);
	data->img[1] = mlx_xpm_file_to_image(data->mlx,
			"srcs/textures/bombardiro2.xpm", &data->img_width,
			&data->img_height);
	data->img[2] = mlx_xpm_file_to_image(data->mlx,
			"srcs/textures/bombardiro3.xpm", &data->img_width,
			&data->img_height);
	data->img[3] = mlx_xpm_file_to_image(data->mlx,
			"srcs/textures/bombardiro4.xpm", &data->img_width,
			&data->img_height);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "srcs/textures/paper.xpm",
			&data->img_width, &data->img_height);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "srcs/textures/floor.xpm",
			&data->img_width, &data->img_height);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, "srcs/textures/wall.xpm",
			&data->img_width, &data->img_height);
	data->img[7] = mlx_xpm_file_to_image(data->mlx,
			"srcs/textures/exit_close.xpm", &data->img_width,
			&data->img_height);
	data->img[8] = mlx_xpm_file_to_image(data->mlx,
			"srcs/textures/exit_open.xpm", &data->img_width, &data->img_height);
	data->img[9] = mlx_xpm_file_to_image(data->mlx, "srcs/textures/shit.xpm",
			&data->img_width, &data->img_height);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	init_texture(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_window,
					data->img[6], j * 32, i * 32);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_window,
					data->img[5], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	render_element(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_window,
					data->img[0], j * 32, i * 32);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_window,
					data->img[4], j * 32, i * 32);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_window,
					data->img[7], j * 32, i * 32);
			j++;
		}
		i++;
	}
}
