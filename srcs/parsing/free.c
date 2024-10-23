/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:41:06 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/21 10:17:01 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../include/cub3d.h"

static void	del_tab_mapping(int **tab, int height)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < height)
	{
		free(tab[i]);
		i++;
	}	
	free(tab);
}

void	destroy_texture(t_data_map *data_map, void *mlx)
{
	if (!mlx)
		return ;
	if (data_map->img_no.img)
		mlx_destroy_image(mlx, data_map->img_no.img);
	if (data_map->img_so.img)
		mlx_destroy_image(mlx, data_map->img_so.img);
	if (data_map->img_we.img)
		mlx_destroy_image(mlx, data_map->img_we.img);
	if (data_map->img_ea.img)
		mlx_destroy_image(mlx, data_map->img_ea.img);
	del_tab_mapping(data_map->mapping_no, data_map->img_no.height);
	del_tab_mapping(data_map->mapping_so, data_map->img_so.height);
	del_tab_mapping(data_map->mapping_we, data_map->img_we.height);
	del_tab_mapping(data_map->mapping_ea, data_map->img_ea.height);
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_data_map(t_data_map *data_map)
{
	if (data_map->file_cub > 0)
		close(data_map->file_cub);
	if (data_map->no)
		free(data_map->no);
	if (data_map->so)
		free(data_map->so);
	if (data_map->we)
		free(data_map->we);
	if (data_map->ea)
		free(data_map->ea);
	if (data_map->map)
		free_map(data_map->map);
}
