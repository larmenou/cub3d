/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:10:15 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/13 08:55:55 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_displayl(int n, unsigned char c, int *len)
{
	int	i;

	i = 0;
	ft_write(c, len);
	if (*len == -1)
		return ;
	while (++i < n)
	{
		ft_write(' ', len);
		if (*len == -1)
			return ;
	}
}

static void	ft_displayr(int n, unsigned char c, int *len)
{
	int	i;

	i = 0;
	while (i++ < n - 1)
	{
		ft_write(' ', len);
		if (*len == -1)
			return ;
	}
	if (*len == -1)
		return ;
	ft_write(c, len);
}

void	ft_ctoc(char *f, unsigned char c, int *len)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (f[i] && (f[i] < '1' || f[i] > '9') && f[i] != '.')
		i++;
	if (f[i])
		n = ft_atoi(&f[i]);
	if (ft_strchr(f, '-'))
		ft_displayl(n, c, len);
	else
		ft_displayr(n, c, len);
}
