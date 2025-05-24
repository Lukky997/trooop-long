/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:04:19 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/24 15:09:05 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "big_libft.h"
# include <mlx.h>

typedef struct s_coordinates
{
	int		x;
	int		y;
}			t_xy;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	void	*img[256];
	int		img_width;
	int		img_height;
	char	**map;
	int		map_width;
	int		map_height;
	t_xy	coord;
	int		count;
	int		move;
	int		nb_c;

}			t_data;

// UTILS
int			exit_error(int nb);
void		free_map(char **map);

// PARSING
int			is_map_clean(char *map);
int			is_map_rectangular(char **map);
int			is_wall_closed(char **map);
int			check_map_element(t_data *data, char element);
int			check_char_map(char **map);
int			is_ber_file(const char *filename);

// MAKE 2D MAP
void		make_map_2d(t_data *data, const char *filename);
char		*read_map_file(const char *filename);

// TEXTURES
void		render_map(t_data *data);
void		render_element(t_data *data);

// KEY PRESSED
int			handle_keypress(int keycode, t_data *data);

#endif