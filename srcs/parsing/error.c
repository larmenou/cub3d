/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:10:01 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/24 11:31:45 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	map_error(int type)
{
	if (type == LINE_NON_CONFORM)
	{
		ft_fprintf(2, "Map contain forbidden character, char allowed: ");
		ft_fprintf(2, "' ', '1', '0', 'N', 'S', 'E', 'W'!\n");
	}
	else if (type == NEW_LINE_IN_MAP)
		ft_fprintf(2, "New line inside/in the end of a map is forbidden!\n");
	else if (type == NO_MAP)
		ft_fprintf(2, "No map in this file!\n");
	else if (type == MUTIPLE_SPAWN_POS)
		ft_fprintf(2, "2 or more spawning position!\n");
	else if (type == NO_WALL)
		ft_fprintf(2, "Spawning spot must be surrounded by 0 and 1!\n");
	else if (type == OPEN_MAP)
		ft_fprintf(2, "0 must be surrounded by 1 only!\n");
	else if (type == NO_PLAYER)
		ft_fprintf(2, "No starting position!\n");
}

void	ft_error_and_exit(int type, char *str, t_data_map *data_map,
	char *to_free)
{
	free_data_map(data_map);
	ft_fprintf(2, "Error\n");
	if (to_free)
		free(to_free);
	if (type == MALLOC_ERROR)
		ft_fprintf(2, "Error during malloc, the program will quit!\n");
	else if (type == DUPLICATE)
		ft_fprintf(2, "%s is duplicate in the file!\n", str);
	else if (type == MISSING_MAP_ELEMENTS)
		ft_fprintf(2, "Map elements are missing!\n");
	else if (type == BAD_TEXTURE)
		ft_fprintf(2, "Error during texture initialization!\n");
	else if (type == NO_TEXTURE_FILE)
		ft_fprintf(2, "The %s texture file cannot be opened!\n", str);
	else if (type == BAD_RGB)
		ft_fprintf(2, "BAD_RGB colors to set like this [0,0,0]!\n");
	else if (type == BAD_RGB_RANGE)
		ft_fprintf(2, "BAD_RGB_RANGE colors in range [0,255]!\n");
	else if (type == BAD_PATH)
		ft_fprintf(2, "BAD_PATH usage : \"%s ./path_to_the_north_texture\"!\n",
			str);
	else if (type == BAD_PATH2)
		ft_fprintf(2, "BAD_PATH usage : \"%s 0,0,0\"!\n", str);
	map_error(type);
	exit(EXIT_FAILURE);
}

void	ft_error_and_exit_fd(int type)
{
	ft_fprintf(2, "Error\n");
	if (type == BAD_ARG)
		ft_fprintf(2, "Usage ./cub3D *.cub!\n");
	if (type == BAD_FD)
		perror("BAD_FD");
	exit(EXIT_FAILURE);
}
