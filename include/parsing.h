/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:14:14 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/24 11:22:40 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "struct.h"
# include "../libft/inc/libft.h"

# define MALLOC_ERROR 1
# define DUPLICATE 2
# define LINE_NON_CONFORM 3
# define NEW_LINE_IN_MAP 4
# define NO_MAP 5
# define MUTIPLE_SPAWN_POS 6
# define NO_WALL 7
# define OPEN_MAP 8
# define MISSING_MAP_ELEMENTS 9
# define NO_PLAYER 10
# define NO_TEXTURE_FILE 11
# define BAD_RGB 12
# define BAD_RGB_RANGE 13
# define BAD_PATH 14
# define BAD_ARG 15
# define BAD_FD 16
# define BAD_TEXTURE 17
# define BAD_PATH2 18

/*main_parsing.c*/
void	get_data_map(int ac, char **av, t_data_map *data_map);

/*error.c*/
void	ft_error_and_exit(int type, char *str,	
			t_data_map *data_map, char *to_free);
void	ft_error_and_exit_fd(int type);

/*read_file.c*/
void	get_data(int fd, t_data_map *data_map);

/*free.c*/
void	free_data_map(t_data_map *data_map);
void	destroy_texture(t_data_map *data_map, void *mlx);

/*set_nsew_in_data.c*/
void	get_texture_path(char *str, t_data_map *data_map, char *to_free);

/*set_map.c*/
void	set_map(int fd, char *buf, t_data_map *data_map);

/*format_map.c*/
void	format_map(char **map, t_data_map *data_map);

/*check_legit_map.c*/
void	map_is_legit(char **map, t_data_map *data_map);

/*set_start_position.c*/
void	set_start_position(char **map, t_data_map *data_map);
void	check_start_position(char **map, t_data_map *data_map);

/*check_map_elements.c*/
void	check_map_elements(t_data_map *data_map, char *buf);

/*display_data_map.c*/
void	display_data_map(t_data_map *data_map);

/*rgb_to_hexa.c*/
int		set_rgb_to_hexa(t_data_map *data_map, char *buf, char *to_free);

/*set_texture.c*/
void	set_texture(t_data_map *data_map, t_data *data);

/*is_spaces.c*/
char	*skip_spaces(char *str);

/*set_noso.c*/
void	set_no(char *str, t_data_map *data_map, char *to_free);
void	set_so(char *str, t_data_map *data_map, char *to_free);

#endif
