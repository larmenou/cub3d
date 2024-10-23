/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:57:56 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/21 16:32:58 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_no_event(void *data)
{
	(void) data;
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	destroy_texture(data->data_map, data->mlx);
	ft_free_mlx(data);
	free_data_map(data->data_map);
	exit(EXIT_SUCCESS);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_exit(data);
		return (0);
	}
	else if (keysym == XK_w)
		forward(data);
	else if (keysym == XK_a)
		left(data);
	else if (keysym == XK_s)
		back(data);
	else if (keysym == XK_d)
		right(data);
	else if (keysym == XK_Right)
		rota_right(data->player);
	else if (keysym == XK_Left)
		rota_left(data->player);
	ft_update(data, data->data_map);
	return (0);
}
