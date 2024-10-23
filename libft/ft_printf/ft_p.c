/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:51:46 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/09 10:58:21 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_l(char *f, void *ptr, int mw, int *len)
{
	t_flags	s;

	s.i = 0;
	s.k = ft_atoi(ft_strchr(f, '.') + 1);
	ft_write('0', len);
	ft_write('x', len);
	s.i = 0;
	while (s.i++ + ft_digit_hex((unsigned long long)ptr) < s.k)
		ft_write('0', len);
	ft_putnbr_ull((unsigned long long)ptr, len);
	while ((int)++s.i + ft_digit_hex((unsigned long long)ptr) < mw)
		ft_write(' ', len);
}

static void	ft_display_r(char *f, void *ptr, int mw, int *len)
{
	t_flags	s;

	s.k = ft_atoi(ft_strchr(f, '.') + 1);
	s.i = 0;
	if (ft_digit_hex((unsigned long long)ptr) > (int)s.k)
	{
		while ((int)s.i++ + ft_digit_hex((unsigned long long)ptr) + 2 < mw)
			ft_write(' ', len);
	}
	else
	{
		while ((int)s.i++ + (int)s.k + 2 < mw)
			ft_write(' ', len);
	}
	ft_write('0', len);
	ft_write('x', len);
	s.i = 0;
	while ((int)s.i++ + ft_digit_hex((unsigned long long)ptr) < (int)s.k)
		ft_write('0', len);
	ft_putnbr_ull((unsigned long long)ptr, len);
}

static void	ft_displayl(void *ptr, int mw, int *len)
{
	int	i;

	i = 0;
	ft_write('0', len);
	ft_write('x', len);
	ft_putnbr_ull((unsigned long long)ptr, len);
	while (i++ < mw - ft_digit_hex((unsigned long long)ptr) - 2)
		ft_write(' ', len);
}	

static void	ft_displayr(char *f, void *ptr, int mw, int *len)
{
	int	i;

	i = 0;
	if (ft_strchr(f, '0') && ft_zeroisflag(f)
		&& mw > ft_digit_hex((unsigned long long)ptr) + 2)
	{
		ft_write('0', len);
		ft_write('x', len);
		while (i++ < mw - ft_digit_hex((unsigned long long)ptr) - 2)
			ft_write('0', len);
	}
	else
	{
		if (mw > ft_digit_hex((unsigned long long)ptr))
		{
			while (i++ < mw - ft_digit_hex((unsigned long long)ptr) - 2)
				ft_write(' ', len);
		}
		ft_write('0', len);
		ft_write('x', len);
	}	
	ft_putnbr_ull((unsigned long long)ptr, len);
}

void	ft_ptos(char *f, void *ptr, int *len)
{
	int	mw;
	int	i;

	i = 0;
	if (!ptr)
	{
		ft_stos_null(f, 'p', len);
		return ;
	}
	while (f[i] && (f[i] < '1' || f[i] > '9') && f[i] != '.')
		i++;
	mw = ft_atoi(&f[i]);
	if (ft_strchr(f, '-') && ft_strchr(f, '.'))
		ft_display_l(f, ptr, mw, len);
	else if (!ft_strchr(f, '-') && ft_strchr(f, '.'))
		ft_display_r(f, ptr, mw, len);
	else if (!ft_strchr(f, '-') && !ft_strchr(f, '.'))
		ft_displayr(f, ptr, mw, len);
	else if (ft_strchr(f, '-') && !ft_strchr(f, '.'))
		ft_displayl(ptr, mw, len);
}
