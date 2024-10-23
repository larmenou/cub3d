/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:05:23 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/23 13:34:59 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>

# include "../minilibx/mlx.h"
# include "../libft/inc/libft.h"
# include "struct.h"
# include "srcs_mlx.h"
# include "parsing.h"

/*
	move.c
*/
void	forward(t_data *data);
void	back(t_data *data);
void	left(t_data *data);
void	right(t_data *data);

/*
	rota.c
*/
void	rota_right(t_player *player);
void	rota_left(t_player *player);

#endif
