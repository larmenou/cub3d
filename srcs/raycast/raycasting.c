/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:46:03 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/23 15:08:58 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_dda(t_data *data, t_ray *ray)
{
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	if (ray->dir_x > 0)
	{
		ray->step_x = 1;
		ray->next_x = (ray->map_x + 1 - data->player->x) * ray->delta_x;
	}
	else
	{
		ray->step_x = -1;
		ray->next_x = (data->player->x - ray->map_x) * ray->delta_x;
	}
	if (ray->dir_y > 0)
	{
		ray->step_y = 1;
		ray->next_y = (ray->map_y + 1 - data->player->y) * ray->delta_y;
	}
	else
	{
		ray->step_y = -1;
		ray->next_y = (data->player->y - ray->map_y) * ray->delta_y;
	}
}

void	dda(t_data *data, t_ray *ray)
{
	int		mur;

	init_dda(data, ray);
	mur = 0;
	while (mur == 0)
	{
		if (ray->next_x < ray->next_y)
		{
			ray->next_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->next_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > data->data_map->map_height - 0.25
			|| ray->map_x > data->data_map->map_width - 0.25)
			break ;
		else if (data->data_map->map[ray->map_y][ray->map_x] > '0')
			mur = 1;
	}
}

void	init_while_ray(t_ray *ray, t_data *data, int ray_cpt)
{
	ray->map_x = (int)data->player->x;
	ray->map_y = (int)data->player->y;
	ray->camera = 2 * ray_cpt / (double)data->width - 1;
	ray->dir_x = data->player->dir_x + data->player->plane_x * ray->camera;
	ray->dir_y = data->player->dir_y + data->player->plane_y * ray->camera;
}

void	affectation_while_ray(t_ray *ray, t_data *data, double distance)
{
	ray->wall_hei = (int)(data->height / distance);
	ray->draw_start = -ray->wall_hei / 2 + data->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->wall_hei / 2 + data->height / 2;
	if (ray->draw_end > data->height)
		ray->draw_end = data->height - 1;
	if (ray->side == 0)
		ray->wall_x = data->player->y + distance * ray->dir_y;
	else
		ray->wall_x = data->player->x + distance * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycasting(t_data *data)
{
	int		ray_cpt;
	t_ray	ray;
	t_point	p;
	double	distance;

	ray_cpt = 0;
	while (ray_cpt < data->width)
	{
		init_while_ray(&ray, data, ray_cpt);
		dda(data, &ray);
		if (ray.side == 0)
			distance = ray.next_x - ray.delta_x;
		else
			distance = ray.next_y - ray.delta_y;
		if (distance < 0.00001)
			distance = 0.00001;
		affectation_while_ray(&ray, data, distance);
		p.x = ray_cpt;
		p.y = ray.draw_start;
		drawline_ceil(ray_cpt, 0, ray.draw_start, data);
		draw_texture(p, data, ray);
		drawline_floor(ray_cpt, ray.draw_end + 1, data->height, data);
		ray_cpt++;
	}
}
