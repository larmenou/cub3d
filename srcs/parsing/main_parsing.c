/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:19:34 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/20 13:52:56 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	init_map_data(int fd, t_data_map *data_map)
{
	ft_bzero(data_map, sizeof(*data_map));
	data_map->start_pos[0] = -1;
	data_map->start_pos[1] = -1;
	data_map->f_color = -1;
	data_map->c_color = -1;
	data_map->file_cub = fd;
}

void	get_data_map(int ac, char **av, t_data_map *data_map)
{
	int			fd;

	if (ac != 2 || ft_strlen(av[1]) < 4)
		ft_error_and_exit_fd(BAD_ARG);
	if (ft_strlen(ft_strnstr(av[1], ".cub", ft_strlen(av[1]))) != 4)
		ft_error_and_exit_fd(BAD_ARG);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error_and_exit_fd(BAD_FD);
	init_map_data(fd, data_map);
	get_data(fd, data_map);
}
