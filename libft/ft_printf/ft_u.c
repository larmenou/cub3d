/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:51:46 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/13 10:12:42 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_l(int mw, int p, unsigned int n, int *len)
{
	int	i;
	int	digit;

	i = 0;
	if (n == 0 && p == 0)
		digit = 0;
	else
		digit = ft_digit_uint(n);
	i = 0;
	while (digit + i < p)
	{
		ft_write('0', len);
		i++;
	}
	if (digit != 0)
		ft_putnbr_uint(n, len);
	while (i++ + digit < mw)
		ft_write(' ', len);
}

static void	ft_display_r(int mw, int p, unsigned int n, int *len)
{
	int	digit;

	if (n == 0 && p == 0)
		digit = 0;
	else
		digit = ft_digit_uint(n);
	if (digit > p)
	{
		while (digit < mw--)
			ft_write(' ', len);
	}
	else
	{
		while (p < mw--)
			ft_write(' ', len);
	}
	while (digit < p--)
		ft_write('0', len);
	if (digit != 0)
		ft_putnbr_uint(n, len);
}	

static void	ft_displayr(char *f, int mw, unsigned int n, int *len)
{
	int		i;
	char	c;

	i = 0;
	if (ft_strchr(f, '0') && ft_zeroisflag(f))
		c = '0';
	else
		c = ' ';
	while (i++ + ft_digit_uint(n) < mw)
		ft_write(c, len);
	ft_putnbr_uint(n, len);
}

static void	ft_displayl(int mw, unsigned int n, int *len)
{
	int	i;

	i = 0;
	ft_putnbr_uint(n, len);
	while (i++ + ft_digit_uint(n) < mw)
		ft_write(' ', len);
}

void	ft_utos(char *f, unsigned int n, int *len)
{
	t_flags	s;

	s.i = 0;
	while (f[s.i] && (f[s.i] < '1' || f[s.i] > '9') && f[s.i] != '.')
		s.i++;
	s.j = ft_atoi(&f[s.i]);
	while (f[s.i] && (f[s.i] >= '0' && f[s.i] <= '9'))
		s.i++;
	if (ft_strchr(f, '.'))
		s.k = ft_atoi(&f[++s.i]);
	else
		s.k = 0;
	if (ft_strchr(f, '-') && ft_strchr(f, '.'))
		ft_display_l(s.j, s.k, n, len);
	else if (!ft_strchr(f, '-') && ft_strchr(f, '.'))
		ft_display_r(s.j, s.k, n, len);
	else if (!ft_strchr(f, '-') && !ft_strchr(f, '.'))
		ft_displayr(f, s.j, n, len);
	else if (ft_strchr(f, '-') && !ft_strchr(f, '.'))
		ft_displayl(s.j, n, len);
}
