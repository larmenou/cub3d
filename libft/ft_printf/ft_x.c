/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:51:02 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/09 10:59:34 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_l(char *f, int mw, unsigned int n, int *len)
{
	t_flags	s;

	s.i = 0;
	s.k = ft_atoi(ft_strchr(f, '.') + 1);
	ft_hashtag(f, n, (int *)&s.i, len);
	if (n == 0 && s.k == 0)
		s.len = 0;
	else
		s.len = ft_digit_uihex(n);
	while (s.len < (int)s.k--)
	{
		ft_write('0', len);
		s.i++;
	}
	if (s.len != 0)
		ft_putnbr_uinthex(f, n, len);
	while ((int)s.i + s.len < mw--)
		ft_write(' ', len);
}

static void	ft_display_r(char *f, int mw, unsigned int n, int *len)
{
	t_flags	s;

	s.k = ft_atoi(ft_strchr(f, '.') + 1);
	if (ft_strchr(f, '#'))
		mw = mw - 2;
	if (n == 0 && s.k == 0)
		s.len = 0;
	else
		s.len = ft_digit_uihex(n);
	if (s.len > (int)s.k)
	{
		while (s.len < mw--)
			ft_write(' ', len);
	}
	else
	{
		while ((int)s.k < mw--)
			ft_write(' ', len);
	}
	ft_hashtag(f, n, (int *)&mw, len);
	while (s.len < (int)s.k--)
		ft_write('0', len);
	if (s.len != 0)
		ft_putnbr_uinthex(f, n, len);
}

static void	ft_displayr(char *f, int mw, unsigned int n, int *len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strchr(f, '#') && n != 0)
		mw = mw - 2;
	if (ft_strchr(f, '0') && ft_zeroisflag(f) && mw > ft_digit_uihex(n))
	{
		ft_hashtag(f, n, (int *)&j, len);
		while (i++ < mw - ft_digit_uihex(n))
			ft_write('0', len);
	}
	else
	{
		if (mw > ft_digit_uihex(n))
		{
			while (i++ < mw - ft_digit_uihex(n))
				ft_write(' ', len);
		}
		ft_hashtag(f, n, (int *)&mw, len);
	}
	ft_putnbr_uinthex(f, n, len);
}

static void	ft_displayl(char *f, int mw, unsigned int n, int *len)
{
	int	i;

	i = 0;
	ft_hashtag(f, n, &i, len);
	ft_putnbr_uinthex(f, n, len);
	while (i++ < mw - ft_digit_uihex(n))
		ft_write(' ', len);
}	

void	ft_xtos(char *f, unsigned int n, int *len)
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
