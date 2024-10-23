/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:18:42 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/23 12:45:35 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_MLX_H
# define SRCS_MLX_H

# include "cub3d.h"
# include "parsing.h"
# include "struct.h"

/*
	mlx.c
*/
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		ft_init_mlx(t_data *data, t_data_map *data_map);
void	ft_img_mlx(t_data *data);
void	ft_update(t_data *data, t_data_map *data_map);

/*
	draw.c
*/
void	drawline(int x1, int y1, int y2, t_data *data);
void	drawline_ceil(int x1, int y1, int y2, t_data *data);
void	drawline_floor(int x1, int y1, int y2, t_data *data);

/*
	texture.c
*/
void	draw_texture(t_point p, t_data *data, t_ray ray);

/*
	raycasting.c
*/
void	raycasting(t_data *data);

/*
	events.c
*/
int		handle_no_event(void *data);
int		ft_exit(t_data *data);
int		handle_keypress(int keysym, t_data *data);

/*
	print_map.c
*/
void	set_player(t_data_map data_map, t_data *data);

/*
	free_mlx.c
*/
void	ft_free_mlx(t_data *data);
int		ft_free_img(t_data *data);

#endif
