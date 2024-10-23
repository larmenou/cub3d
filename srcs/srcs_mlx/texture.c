/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:44:26 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/23 12:44:54 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_tex_data(t_data *data, t_ray ray, t_tex *t, t_img img)
{
	t->w = img.width;
	t->x_tex = (int)(ray.wall_x * t->w);
	if ((ray.side == 0 && ray.dir_x < 0)
		|| (ray.side == 1 && ray.dir_y > 0))
		t->x_tex = t->w - t->x_tex - 1;
	t->step = 1.0 * t->w / ray.wall_hei;
	t->pos = (ray.draw_start - data->height / 2 + ray.wall_hei / 2) * t->step;
}

void	get_texture(t_data *data, t_ray ray, t_tex *t)
{
	if (ray.side == 1)
	{
		if (ray.dir_y > 0)
			get_tex_data(data, ray, t, data->data_map->img_so);
		else
			get_tex_data(data, ray, t, data->data_map->img_no);
	}
	else
	{
		if (ray.dir_x > 0)
			get_tex_data(data, ray, t, data->data_map->img_ea);
		else
			get_tex_data(data, ray, t, data->data_map->img_we);
	}
}

int	get_color(t_data *data, t_ray ray, t_tex t)
{
	if (ray.side == 1)
	{
		if (ray.dir_y > 0)
			return (data->data_map->mapping_so[t.y_tex][t.x_tex]);
		else
			return (data->data_map->mapping_no[t.y_tex][t.x_tex]);
	}
	else
	{
		if (ray.dir_x > 0)
			return (data->data_map->mapping_ea[t.y_tex][t.x_tex]);
		else
			return (data->data_map->mapping_we[t.y_tex][t.x_tex]);
	}
	return (-1);
}

void	draw_texture(t_point p, t_data *data, t_ray ray)
{
	t_tex	t;

	get_texture(data, ray, &t);
	while (p.y < ray.draw_end)
	{
		t.y_tex = (int)t.pos & (t.w - 1);
		t.pos += t.step;
		t.color = get_color(data, ray, t);
		my_mlx_pixel_put(&data->img, p.x, p.y, t.color);
		p.y++;
	}
}
