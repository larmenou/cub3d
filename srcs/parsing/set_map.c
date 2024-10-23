/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:13:59 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/13 13:41:22 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

/*y + 2 because we will add 1 line + 1 Null*/

static char	**add_line(char *to_add, char **map, int *y, t_data_map *data_map)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof (*new_map) * (*y + 2));
	if (!new_map)
		ft_error_and_exit(MALLOC_ERROR, NULL, data_map, to_add);
	while (map && map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = to_add;
	i++;
	new_map[i] = NULL;
	*y = *y + 1;
	free(map);
	return (new_map);
}

static bool	line_is_conform(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '0' && str[i] != '1' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return (false);
		i++;
	}
	return (true);
}

static int	set_width(char **map)
{
	int	i;
	int	x;
	int	x_buf;

	i = 0;
	x = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		x_buf = ft_strlen(map[i]);
		if (x_buf > x)
			x = x_buf;
		i++;
	}
	return (x);
}

/*no buf free here, map** point to every
	buf and will be free when we free map**
	if buf empty : EOF and no map is in the file*/

void	set_map(int fd, char *buf, t_data_map *data_map)
{
	char	*buf_to_free;

	if (!buf)
		ft_error_and_exit(NO_MAP, NULL, data_map, NULL);
	while (buf)
	{
		if (buf[0] == '\n')
			ft_error_and_exit(NEW_LINE_IN_MAP, NULL, data_map, buf);
		buf_to_free = buf;
		buf = ft_strtrim(buf, "\n");
		free(buf_to_free);
		if (!buf)
			ft_error_and_exit(MALLOC_ERROR, NULL, data_map, NULL);
		else if (line_is_conform(buf) == false)
			ft_error_and_exit(LINE_NON_CONFORM, NULL, data_map, buf);
		data_map->map = add_line(buf, data_map->map, &data_map->map_height,
				data_map);
		buf = get_next_line(fd);
	}
	data_map->map_width = set_width(data_map->map);
}
