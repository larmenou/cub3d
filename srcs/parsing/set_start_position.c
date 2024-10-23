/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:43:11 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/21 09:49:41 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	surrounded_by_wall(char **map, t_data_map *data_map, int i, int j)
{
	if (map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != '0')
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	else if (map[i - 1][j] != '1' && map[i - 1][j] != '0')
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	else if (map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != '0')
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	else if (map[i][j + 1] != '1' && map[i][j + 1] != '0')
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	else if (map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '0')
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	else if (map[i + 1][j] != '1' && map[i + 1][j] != '0')
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	else if (map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != '0')
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	else if (map[i][j - 1] != '1' && map[i][j - 1] != '0')
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
}

static void	pos_is_legit(char **map, t_data_map	*data_map, int i, int j)
{
	if (data_map->spawn_or != 0)
		ft_error_and_exit(MUTIPLE_SPAWN_POS, NULL, data_map, NULL);
	if (j == 0 || i == 0 || !map[i][j + 1] || i == data_map->map_height - 1)
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	if ((size_t)j >= ft_strlen(map[i - 1]) + 1
		|| (size_t)j >= ft_strlen(map[i + 1]) + 1)
		ft_error_and_exit(NO_WALL, NULL, data_map, NULL);
	surrounded_by_wall(map, data_map, i, j);
}

void	check_start_position(char **map, t_data_map *data_map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{	
				pos_is_legit(map, data_map, i, j);
				data_map->start_pos[0] = j;
				data_map->start_pos[1] = i;
				data_map->spawn_or = map[i][j];
				map[i][j] = '0';
			}	
			j++;
		}
		i++;
	}
}
