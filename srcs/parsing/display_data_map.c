/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:35:39 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/16 16:36:01 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	display_map(t_data_map *data_map)
{
	int	i;

	i = 0;
	while (data_map->map[i])
	{
		ft_printf("%s\n", data_map->map[i]);
		i++;
	}
}

void	display_data_map(t_data_map *data_map)
{
	ft_printf("rgb c = %i\n", data_map->c_color);
	ft_printf("rgb f = %i\n", data_map->f_color);
	ft_printf("Width = %i\n", data_map->map_width);
	ft_printf("Height = %i\n", data_map->map_height);
	ft_printf("Spawn_or = %c\n", data_map->spawn_or);
	ft_printf("Starting position x=%i y=%i\n", data_map->start_pos[0],
		data_map->start_pos[1]);
	ft_printf("%s\n", data_map->no);
	ft_printf("%s\n", data_map->so);
	ft_printf("%s\n", data_map->we);
	ft_printf("%s\n", data_map->ea);
	display_map(data_map);
}
