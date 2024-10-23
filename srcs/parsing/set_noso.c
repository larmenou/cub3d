/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_noso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:21:20 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/24 10:22:26 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	set_no(char *str, t_data_map *data_map, char *to_free)
{
	if (!ft_strncmp(str, "NO", 2))
	{
		if (data_map->no)
		{
			free(to_free);
			ft_error_and_exit(DUPLICATE, "NO", data_map, str);
		}	
		data_map->no = ft_strdup(skip_spaces(str + 2));
		if (!data_map->no)
		{
			free(to_free);
			ft_error_and_exit(MALLOC_ERROR, NULL, data_map, str);
		}	
	}
}

void	set_so(char *str, t_data_map *data_map, char *to_free)
{
	if (!ft_strncmp(str, "SO", 2))
	{
		if (data_map->so)
		{
			free(to_free);
			ft_error_and_exit(DUPLICATE, "SO", data_map, str);
		}	
		data_map->so = ft_strdup(skip_spaces(str + 2));
		if (!data_map->so)
		{
			free(to_free);
			ft_error_and_exit(MALLOC_ERROR, NULL, data_map, str);
		}	
	}
}
