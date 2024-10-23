/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:19:37 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/16 16:35:42 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	check_texture_files(t_data_map *data_map, char *buf)
{
	int	fd;

	fd = open(data_map->no, O_RDONLY);
	if (fd == -1)
		ft_error_and_exit(NO_TEXTURE_FILE, "NO", data_map, buf);
	else
		close(fd);
	fd = open(data_map->so, O_RDONLY);
	if (fd == -1)
		ft_error_and_exit(NO_TEXTURE_FILE, "SO", data_map, buf);
	else
		close(fd);
	fd = open(data_map->we, O_RDONLY);
	if (fd == -1)
		ft_error_and_exit(NO_TEXTURE_FILE, "WE", data_map, buf);
	else
		close(fd);
	fd = open(data_map->ea, O_RDONLY);
	if (fd == -1)
		ft_error_and_exit(NO_TEXTURE_FILE, "EA", data_map, buf);
	else
		close(fd);
}

void	check_map_elements(t_data_map *data_map, char *buf)
{
	if (!data_map->no || !data_map->so || !data_map->we
		|| !data_map->ea || data_map->f_color == -1 || data_map->c_color == -1)
		ft_error_and_exit(MISSING_MAP_ELEMENTS, NULL, data_map, buf);
	check_texture_files(data_map, buf);
}
