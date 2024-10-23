/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nsew_in_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:07:59 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/24 10:26:58 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	set_we(char *str, t_data_map *data_map, char *to_free)
{
	if (!ft_strncmp(str, "WE", 2))
	{
		if (data_map->we)
		{
			free(to_free);
			ft_error_and_exit(DUPLICATE, "WE", data_map, str);
		}	
		data_map->we = ft_strdup(skip_spaces(str + 2));
		if (!data_map->we)
		{
			free(to_free);
			ft_error_and_exit(MALLOC_ERROR, NULL, data_map, str);
		}	
	}
}

static void	set_ea(char *str, t_data_map *data_map, char *to_free)
{
	if (!ft_strncmp(str, "EA", 2))
	{
		if (data_map->ea)
		{
			free(to_free);
			ft_error_and_exit(DUPLICATE, "EA", data_map, str);
		}	
		data_map->ea = ft_strdup(skip_spaces(str + 2));
		if (!data_map->ea)
		{
			free(to_free);
			ft_error_and_exit(MALLOC_ERROR, NULL, data_map, str);
		}		
	}
}

static void	check_fc(char *str, t_data_map *data_map, char *to_free)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = skip_spaces(str + 1);
	while (tmp[i])
	{
		if (tmp[i] == ' ')
		{
			while (tmp[i] == ' ')
				i++;
		}
		else if ((tmp[i] < '0' || tmp[i] > '9') && tmp[i] != ',')
		{
			free(to_free);
			ft_error_and_exit(BAD_RGB, NULL, data_map, str);
		}
		else
			i++;
	}
}

static void	set_fc(char *str, t_data_map *data_map, char *to_free)
{
	if (!ft_strncmp(str, "F", 1))
	{
		if (data_map->f_color != -1)
		{
			free(to_free);
			ft_error_and_exit(DUPLICATE, "F", data_map, str);
		}	
		check_fc(str, data_map, to_free);
		data_map->f_color = set_rgb_to_hexa(data_map, str, to_free);
	}
	else if (!ft_strncmp(str, "C", 1))
	{
		if (data_map->c_color != -1)
		{
			free(to_free);
			ft_error_and_exit(DUPLICATE, "C", data_map, str);
		}	
		check_fc(str, data_map, to_free);
		data_map->c_color = set_rgb_to_hexa(data_map, str, to_free);
	}
}

void	get_texture_path(char *str, t_data_map *data_map, char *to_free)
{
	set_no(str, data_map, to_free);
	set_so(str, data_map, to_free);
	set_we(str, data_map, to_free);
	set_ea(str, data_map, to_free);
	set_fc(str, data_map, to_free);
}
