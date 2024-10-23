/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 08:43:59 by bahommer          #+#    #+#             */
/*   Updated: 2023/03/20 09:24:19 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stos_fd(int fd, char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		ft_write_fd(fd, str[i++], len);
}