/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:19:45 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/13 13:41:48 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static char	*extend(char *str, t_data_map *data_map, int j)
{
	char	*new_line;
	char	*to_free;
	int		i;

	i = 0;
	new_line = malloc(sizeof (char *) * (data_map->map_width - j + 1));
	if (!new_line)
		ft_error_and_exit(MALLOC_ERROR, NULL, data_map, NULL);
	while (i < data_map->map_width - j)
	{
		new_line[i] = '1';
		i++;
	}
	new_line[i] = '\0';
	to_free = new_line;
	new_line = ft_strjoin(str, new_line);
	if (!new_line)
		ft_error_and_exit(MALLOC_ERROR, NULL, data_map, to_free);
	free(str);
	free(to_free);
	return (new_line);
}

void	format_map(char **map, t_data_map *data_map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		if (j < data_map->map_width)
			map[i] = extend(map[i], data_map, j);
		i++;
	}
}
