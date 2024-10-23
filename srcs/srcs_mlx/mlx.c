/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:52:25 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/23 14:06:12 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x <= 900 && y <= 600))
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
	else
		dst = NULL;
}

int	ft_init_mlx(t_data *data, t_data_map *data_map)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3D");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_data_map(data_map);
		return (0);
	}
	set_texture(data_map, data);
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img.img)
		return (ft_free_img(data));
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (1);
}

void	ft_update(t_data *data, t_data_map *data_map)
{
	(void) data_map;
	mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	ft_img_mlx(t_data *data)
{
	mlx_loop_hook(data->mlx, &handle_no_event, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &ft_exit, data);
	mlx_loop(data->mlx);
}
