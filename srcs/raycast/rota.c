/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:41:22 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/23 12:40:28 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rota_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(-player->rota) - player->dir_y
		* sin(-player->rota);
	player->dir_y = old_dir_x * sin(-player->rota) + player->dir_y
		* cos(-player->rota);
	player->plane_x = player->plane_x * cos(-player->rota) - player->plane_y
		* sin(-player->rota);
	player->plane_y = old_plane_x * sin(-player->rota) + player->plane_y
		* cos(-player->rota);
}

void	rota_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(player->rota) - player->dir_y
		* sin(player->rota);
	player->dir_y = old_dir_x * sin(player->rota) + player->dir_y
		* cos(player->rota);
	player->plane_x = player->plane_x * cos(player->rota) - player->plane_y
		* sin(player->rota);
	player->plane_y = old_plane_x * sin(player->rota) + player->plane_y
		* cos(player->rota);
}
