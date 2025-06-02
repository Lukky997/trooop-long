/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:03:55 by lgoras            #+#    #+#             */
/*   Updated: 2025/06/02 15:45:21 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cleanup_images(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		if (data->img[i] && data->mlx)
		{
			mlx_destroy_image(data->mlx, data->img[i]);
			data->img[i] = NULL;
		}
	}
}

static void	cleanup_resources(t_data *data)
{
	if (!data)
		return ;
	cleanup_images(data);
	if (data->map)
	{
		free_map(data->map);
		data->map = NULL;
	}
	if (data->mlx_window && data->mlx)
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
		data->mlx_window = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

int	close_window(t_data *data)
{
	cleanup_resources(data);
	exit(0);
	return (0);
}

int	exit_error(char *error, t_data *data)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0m", 2);
	cleanup_resources(data);
	exit(EXIT_FAILURE);
	return (0);
}

void	winner(t_data *data)
{
	ft_printf("\033[1;92m===================\n");
	ft_printf("|| Good boy 🐶 ! ||\n");
	ft_printf("===================\033[0;39m\n");
	cleanup_resources(data);
	exit(EXIT_SUCCESS);
}
