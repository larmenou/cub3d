/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:51:46 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/13 11:21:01 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_l(char *f, int mw, int n, int *len)
{
	t_flags	s;

	s.i = 0;
	s.j = 0;
	s.k = ft_atoi(ft_strchr(f, '.') + 1);
	ft_write_sign(f, n, len, (int *)&s.j);
	if (n == 0 && s.k == 0)
		s.len = 0;
	else
		s.len = ft_digit(n);
	while (s.len + (int)s.i < (int)s.k)
	{
		ft_write('0', len);
		s.i++;
	}
	if (s.len != 0)
		ft_putnbr_mod(n, len);
	while ((int)s.i++ + s.len + (int)s.j < mw)
		ft_write(' ', len);
}

static void	ft_display_r(char *f, int mw, int n, int *len)
{
	t_flags	s;

	s.k = ft_atoi(ft_strchr(f, '.') + 1);
	s.i = 0;
	if (n == 0 && s.k == 0)
		s.len = 0;
	else
		s.len = ft_digit(n);
	if (n < 0 || ft_strchr(f, '+') || ft_strchr(f, ' '))
		s.i++;
	if (s.len > (int)s.k)
	{
		while ((int)s.i + s.len < mw--)
			ft_write(' ', len);
	}
	else
	{
		while ((int)s.i + (int)s.k < mw--)
			ft_write(' ', len);
	}
	ft_write_sign(f, n, len, (int *)&s.i);
	while (s.len < (int)s.k--)
		ft_write('0', len);
	if (s.len != 0)
		ft_putnbr_mod(n, len);
}

static void	ft_displayr(char *f, int mw, int n, int *len)
{
	int		i;
	char	c;

	i = 0;
	if (ft_strchr(f, '0') && ft_zeroisflag(f))
		c = '0';
	else
		c = ' ';
	if (ft_strchr(f, '0') && ft_zeroisflag(f))
		ft_write_sign(f, n, len, &i);
	else if (n < 0 || ft_strchr(f, '+') || ft_strchr(f, ' '))
		i++;
	while (i++ + ft_digit(n) < mw)
		ft_write(c, len);
	if (!ft_zeroisflag(f))
		ft_write_sign(f, n, len, &i);
	ft_putnbr_mod(n, len);
}

static void	ft_displayl(char *f, int mw, int n, int *len)
{
	int	i;

	i = 0;
	ft_write_sign(f, n, len, &i);
	ft_putnbr_mod(n, len);
	while (i++ + ft_digit(n) < mw)
		ft_write(' ', len);
}	

void	ft_itos(char *f, int n, int *len)
{
	t_flags	s;

	s.i = 0;
	while (f[s.i] && (f[s.i] < '1' || f[s.i] > '9') && f[s.i] != '.')
		s.i++;
	s.j = ft_atoi(&f[s.i]);
	if (ft_strchr(f, '-') && ft_strchr(f, '.'))
		ft_display_l(f, s.j, n, len);
	else if (!ft_strchr(f, '-') && ft_strchr(f, '.'))
		ft_display_r(f, s.j, n, len);
	else if (!ft_strchr(f, '-') && !ft_strchr(f, '.'))
		ft_displayr(f, s.j, n, len);
	else if (ft_strchr(f, '-') && !ft_strchr(f, '.'))
		ft_displayl(f, s.j, n, len);
}
