/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:03:55 by lgoras            #+#    #+#             */
/*   Updated: 2025/06/02 14:56:15 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img[0]);
	mlx_destroy_image(data->mlx, data->img[1]);
	mlx_destroy_image(data->mlx, data->img[2]);
	mlx_destroy_image(data->mlx, data->img[3]);
	mlx_destroy_image(data->mlx, data->img[4]);
	mlx_destroy_image(data->mlx, data->img[5]);
	mlx_destroy_image(data->mlx, data->img[6]);
	mlx_destroy_image(data->mlx, data->img[7]);
	mlx_destroy_image(data->mlx, data->img[8]);
	mlx_destroy_image(data->mlx, data->img[9]);
	free_map(data->map);
}

int	close_window(t_data *data)
{
	free_exit(data);
	mlx_destroy_window(data->mlx, data->mlx_window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	exit_error(char *error)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}

void	winner(t_data *data)
{
	ft_printf("\033[1;92m===================\n");
	ft_printf("|| Good boy 🐶 ! ||\n");
	ft_printf("===================\033[0;39m\n");
	close_window(data);
	exit(EXIT_SUCCESS);
}
