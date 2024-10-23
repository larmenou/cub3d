/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:08:36 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/24 11:31:17 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

static void	check_rgb(t_data_map *data_map, char *buf, t_rgb rgb, char *to_free)
{
	if (rgb.r > 255 || rgb.r < 0 || rgb.g > 255 || rgb.g < 0
		|| rgb.b > 255 || rgb.b < 0)
	{
		free(to_free);
		ft_error_and_exit(BAD_RGB_RANGE, NULL, data_map, buf);
	}
}

static void	check_end_rgb(char *str, t_data_map *data_map, char *buf,
	char *to_free)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
	{
		free(to_free);
		ft_error_and_exit(BAD_RGB, NULL, data_map, buf);
	}	
}

static void	set_rgb_to_hexa_second(t_data_map *data_map, char **tmp,
	char *to_free, char *buf)
{
	int	i;

	i = 0;
	while ((*tmp)[i] && (*tmp)[i] >= '0' && (*tmp)[i] <= '9')
		i++;
	*tmp = skip_spaces(&(*tmp)[i]);
	if (!*tmp || *tmp[0] == '\0' || *tmp[0] != ',')
	{
		free(to_free);
		ft_error_and_exit(BAD_RGB, NULL, data_map, buf);
	}	
	*tmp = *tmp + 1;
	*tmp = skip_spaces(*tmp);
}

static void	check_number(t_data_map *data_map, char *tmp, char *to_free,
	char *buf)
{
	if (!tmp || tmp[0] < '0' || tmp[0] > '9')
	{
		free(to_free);
		ft_error_and_exit(BAD_RGB, NULL, data_map, buf);
	}
}

int	set_rgb_to_hexa(t_data_map *data_map, char *buf, char *to_free)
{
	char	*tmp;
	t_rgb	rgb;

	tmp = skip_spaces(buf + 1);
	check_number(data_map, tmp, to_free, buf);
	rgb.r = ft_atoi(tmp);
	set_rgb_to_hexa_second(data_map, &tmp, to_free, buf);
	check_number(data_map, tmp, to_free, buf);
	rgb.g = ft_atoi(tmp);
	set_rgb_to_hexa_second(data_map, &tmp, to_free, buf);
	check_number(data_map, tmp, to_free, buf);
	rgb.b = ft_atoi(tmp);
	check_end_rgb(tmp, data_map, buf, to_free);
	check_rgb(data_map, buf, rgb, to_free);
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}
