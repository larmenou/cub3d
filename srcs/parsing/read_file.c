/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:48:16 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/24 10:15:15 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

/*if no new line or no path texture, this is the map,
	we will gnl in a new function
warning : buf is not empty it contains first line of map*/

static void	map_part(int fd, char *buf, t_data_map *data_map)
{
	set_map(fd, buf, data_map);
	check_start_position(data_map->map, data_map);
	map_is_legit(data_map->map, data_map);
	if (!data_map->spawn_or)
		ft_error_and_exit(NO_PLAYER, NULL, data_map, NULL);
	format_map(data_map->map, data_map);
	close(fd);
}

static void	handle_nosoweeafc(char **buf, t_data_map *data_map, char *str)
{
	char	*buf_to_free;

	buf_to_free = *buf;
	*buf = ft_strtrim(*buf, "\n");
	free(buf_to_free);
	if (!*buf)
		ft_error_and_exit(MALLOC_ERROR, NULL, data_map, str);
	buf_to_free = *buf;
	*buf = ft_strtrim(*buf, " ");
	free(buf_to_free);
	if (!*buf)
		ft_error_and_exit(MALLOC_ERROR, NULL, data_map, str);
	get_texture_path(*buf, data_map, str);
}

void	get_data(int fd, t_data_map *data_map)
{
	char	*buf;
	char	*tmp;

	buf = get_next_line(fd);
	tmp = NULL;
	while (buf)
	{
		tmp = ft_strdup(skip_spaces(buf));
		if (!ft_strncmp(tmp, "NO", 2) || !ft_strncmp(tmp, "SO", 2)
			|| !ft_strncmp(tmp, "WE", 2) || !ft_strncmp(tmp, "EA", 2)
			|| !ft_strncmp(tmp, "F", 1) || !ft_strncmp(tmp, "C", 1))
			handle_nosoweeafc(&tmp, data_map, buf);
		else if (buf[0] != '\n')
			break ;
		free(buf);
		free(tmp);
		buf = get_next_line(fd);
	}
	if (tmp)
		free(tmp);
	check_map_elements(data_map, buf);
	map_part(fd, buf, data_map);
}
