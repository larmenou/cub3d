/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:23:21 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/23 14:06:04 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_data_map	data_map;
	t_player	player;

	get_data_map(ac, av, &data_map);
	data.player = &player;
	data.player->x = (double)data_map.start_pos[0] + 0.5;
	data.player->y = (double)data_map.start_pos[1] + 0.5;
	data.player->move = 0.05;
	data.player->rota = 0.05;
	data.data_map = &data_map;
	data.height = 600;
	data.width = 900;
	set_player(data_map, &data);
	if (!ft_init_mlx(&data, &data_map))
	{
		free_data_map(&data_map);
		return (-1);
	}
	ft_img_mlx(&data);
	free_data_map(&data_map);
	return (0);
}
