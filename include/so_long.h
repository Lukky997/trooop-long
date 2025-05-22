/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:04:19 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/22 20:10:33 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "big_libft.h"

typedef struct s_coordinates
{
	int		x;
	int		y;
}			t_xy;

typedef struct s_data
{
	char	**map;
	t_xy	coord;
	int		count;
	int		nbr_c;

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

// MAKE 2D MAP
void		make_map_2d(t_data *data, const char *filename);
char		*read_map_file(const char *filename);

#endif