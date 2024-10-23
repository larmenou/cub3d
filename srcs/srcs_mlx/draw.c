/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:41:22 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/23 12:41:40 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	drawline(int x1, int y1, int y2, t_data *data)
{
	int	y;

	y = y1;
	while (y < y2)
	{
		my_mlx_pixel_put(&data->img, x1, y, 0x006400);
		y++;
	}
}

void	drawline_ceil(int x1, int y1, int y2, t_data *data)
{
	int	y;

	y = y1;
	while (y < y2)
	{
		my_mlx_pixel_put(&data->img, x1, y, data->data_map->c_color);
		y++;
	}
}

void	drawline_floor(int x1, int y1, int y2, t_data *data)
{
	int	y;

	y = y1;
	while (y < y2)
	{
		my_mlx_pixel_put(&data->img, x1, y, data->data_map->f_color);
		y++;
	}
}
