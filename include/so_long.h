/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:04:19 by lgoras            #+#    #+#             */
/*   Updated: 2025/06/02 15:20:54 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "big_libft.h"
# include <mlx.h>

# define W 119
# define S 115
# define A 97
# define D 100

# define MAX_MAP_WIDTH 100
# define MAX_MAP_HEIGHT 100

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
int			exit_error(char *error, t_data *data);
void		free_map(char **map);
int			close_window(t_data *data);
void		winner(t_data *data);

// PARSING
int			is_map_clean(char *map);
int			is_map_rectangular(char **map);
int			is_wall_closed(char **map);
int			check_map_element(t_data *data, char element);
int			check_char_map(char **map);
int			is_ber_file(const char *filename);
void		check_path(t_data *data);

// MAKE 2D MAP
void		set_map_size(t_data *data);
void		make_map_2d(t_data *data, const char *filename);
char		*read_map_file(const char *filename, t_data *data);

// TEXTURES
void		init_texture(t_data *data);
void		render_map(t_data *data);
void		render_element(t_data *data);

// KEY PRESSED
int			handle_keypress(int keycode, t_data *data);

#endif