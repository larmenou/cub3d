/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:11:07 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/23 13:13:12 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_player {
	double	x;
	double	y;
	double	move;
	double	rota;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
}				t_player;

typedef struct s_data_map
{
	int		file_cub;
	char	spawn_or;
	int		start_pos[2];
	int		map_width;
	int		map_height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_img	img_no;
	t_img	img_so;
	t_img	img_we;
	t_img	img_ea;
	int		**mapping_no;
	int		**mapping_so;
	int		**mapping_we;
	int		**mapping_ea;
	int		f_color;
	int		c_color;
	char	**map;
}	t_data_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	t_img		img;
	t_player	*player;
	t_data_map	*data_map;
}				t_data;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	double	camera;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	next_x;
	double	next_y;
	int		side;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	double	wall_hei;
}				t_ray;

typedef struct s_tex
{
	int		color;
	int		x_tex;
	int		y_tex;
	double	step;
	double	pos;
	int		w;
}				t_tex;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

#endif
