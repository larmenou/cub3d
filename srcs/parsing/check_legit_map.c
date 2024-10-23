/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_legit_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:09:02 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/13 13:36:49 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	zero_surrounded_by_one(char **map, t_data_map *data_map,
	int i, int j)
{
	if (j == 0 || i == 0 || !map[i][j + 1] || i == data_map->map_height - 1)
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	if ((size_t)j >= ft_strlen(map[i - 1] + 1)
		|| (size_t)j >= ft_strlen(map[i + 1] + 1))
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	else if (map[i - 1][j - 1] == ' ')
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	else if (map[i - 1][j] == ' ')
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	else if (map[i - 1][j + 1] == ' ')
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	else if (map[i][j + 1] == ' ')
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	else if (map[i + 1][j + 1] == ' ')
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	else if (map[i + 1][j] == ' ')
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	else if (map[i + 1][j - 1] == ' ')
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
	else if (map[i][j - 1] == ' ')
		ft_error_and_exit(OPEN_MAP, NULL, data_map, NULL);
}

void	map_is_legit(char **map, t_data_map *data_map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				zero_surrounded_by_one(map, data_map, i, j);
			j++;
		}
		i++;
	}
}
