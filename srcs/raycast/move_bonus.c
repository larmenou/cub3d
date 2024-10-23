/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:28 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/23 13:39:07 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	verif_move(t_data *data, double tmp_x, double tmp_y)
{
	if (tmp_x > 0 && tmp_y > 0 && tmp_x < data->data_map->map_width
		&& tmp_y < data->data_map->map_height
		&& data->data_map->map[(int)floor(tmp_y)][(int)floor(tmp_x)] == '0')
	{
		data->player->x = tmp_x;
		data->player->y = tmp_y;
	}
}

void	forward(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->x + data->player->dir_x * data->player->move;
	tmp_y = data->player->y + data->player->dir_y * data->player->move;
	verif_move(data, tmp_x, tmp_y);
}

void	back(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->x - data->player->dir_x * data->player->move;
	tmp_y = data->player->y - data->player->dir_y * data->player->move;
	verif_move(data, tmp_x, tmp_y);
}

void	left(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->x + data->player->dir_y * data->player->move;
	tmp_y = data->player->y - data->player->dir_x * data->player->move;
	verif_move(data, tmp_x, tmp_y);
}

void	right(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->x - data->player->dir_y * data->player->move;
	tmp_y = data->player->y + data->player->dir_x * data->player->move;
	verif_move(data, tmp_x, tmp_y);
}
