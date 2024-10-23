/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:37:48 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/10 13:54:51 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	ft_free_img(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (0);
}
