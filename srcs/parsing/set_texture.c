/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:02:22 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/24 10:44:28 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../include/cub3d.h"

static void	init_texture(char *path, t_img *img, t_data *data,
	t_data_map *data_map)
{
	img->img = mlx_xpm_file_to_image(data->mlx,
			path, &img->width, &img->height);
	if (!img->img || img->width <= 0 || img->height <= 0 || img->width > 64
		|| img->height > 64)
	{
		destroy_texture(data_map, data->mlx);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_error_and_exit(BAD_TEXTURE, NULL, data_map, NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		destroy_texture(data_map, data->mlx);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_error_and_exit(BAD_TEXTURE, NULL, data_map, NULL);
	}
}

static int	**malloc_mapping(t_img *img)
{
	int	**tab;
	int	i;

	i = 0;
	tab = ft_calloc(img->height, sizeof(int *));
	if (!tab)
		return (NULL);
	while (i < img->height)
	{
		tab[i] = ft_calloc(img->width, sizeof(int));
		if (!tab[i])
		{
			while (--i > 0)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
		i++;
	}	
	return (tab);
}

static void	free_cub3d(t_data_map *data_map, t_data *data)
{
	destroy_texture(data_map, data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_error_and_exit(MALLOC_ERROR, NULL, data_map, NULL);
}

static int	**map_texture(t_img *img, t_data_map *data_map, t_data *data)
{	
	int		**tab;
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	tab = malloc_mapping(img);
	if (!tab)
		free_cub3d(data_map, data);
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = img->addr + (y * img->line_length
					+ x * (img->bits_per_pixel / 8));
			tab[y][x] = *(int *)pixel;
			x++;
		}
		y++;
	}
	return (tab);
}

void	set_texture(t_data_map *data_map, t_data *data)
{
	init_texture(data_map->no, &data_map->img_no, data, data_map);
	init_texture(data_map->so, &data_map->img_so, data, data_map);
	init_texture(data_map->we, &data_map->img_we, data, data_map);
	init_texture(data_map->ea, &data_map->img_ea, data, data_map);
	data_map->mapping_no = map_texture(&data_map->img_no, data_map, data);
	data_map->mapping_so = map_texture(&data_map->img_so, data_map, data);
	data_map->mapping_we = map_texture(&data_map->img_we, data_map, data);
	data_map->mapping_ea = map_texture(&data_map->img_ea, data_map, data);
}
