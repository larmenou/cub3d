/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:23:16 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/07 08:49:44 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_l(char *f, char *str, int *len)
{
	int	i;
	int	nm;
	int	np;

	i = 0;
	while (f[i] && (f[i] < '1' || f[i] > '9') && f[i] != '.')
		i++;
	nm = ft_atoi(&f[i]);
	while (f[i] && (f[i] >= '0' && f[i] <= '9'))
		i++;
	np = ft_atoi(&f[++i]);
	i = -1;
	if (np < (int)ft_strlen(str))
	{
		while (++i < nm)
			ft_write(' ', len);
	}
	else
	{	
		while (str[++i] && i < np)
			ft_write(str[i], len);
		while (i++ < nm)
			ft_write(' ', len);
	}
}

static void	ft_display_r(char *f, char *str, int *len)
{
	t_flags	s;

	s.i = 0;
	while (f[s.i] && (f[s.i] < '1' || f[s.i] > '9') && f[s.i] != '.')
		s.i++;
	s.j = ft_atoi(&f[s.i]);
	while (f[s.i] && (f[s.i] >= '0' && f[s.i] <= '9'))
		s.i++;
	s.k = ft_atoi(&f[++s.i]);
	s.i = 0;
	if (s.k < ft_strlen(str))
	{
		while (s.i++ < s.j)
			ft_write(' ', len);
	}
	else
	{
		while ((int)s.i++ < (int)s.j - (int)ft_strlen(str))
			ft_write(' ', len);
		s.i = 0;
		while (str[s.i] && s.i < s.k)
			ft_write(str[s.i++], len);
	}
}

static void	ft_displayl(char *f, char *str, int *len)
{
	int	i;
	int	nm;

	i = 0;
	nm = 0;
	while (f[i] && (f[i] < '1' || f[i] > '9') && f[i] != '.')
		i++;
	nm = ft_atoi(&f[i]);
	while (f[i] && (f[i] >= '0' && f[i] <= '9'))
		i++;
	i = 0;
	while (str[i])
		ft_write(str[i++], len);
	if (nm > (int)ft_strlen(str))
	{
		while (i++ < nm)
			ft_write(' ', len);
	}
}	

static void	ft_displayr(char *f, char *str, int *len)
{
	int	i;
	int	nm;

	i = 0;
	nm = 0;
	while (f[i] && (f[i] < '1' || f[i] > '9') && f[i] != '.')
		i++;
	nm = ft_atoi(&f[i]);
	while (f[i] && (f[i] >= '0' && f[i] <= '9'))
		i++;
	i = 0;
	if (nm > (int)ft_strlen(str))
	{
		while (i++ < nm - (int)ft_strlen(str))
			ft_write(' ', len);
	}
	i = -1;
	while (str[++i])
		ft_write(str[i], len);
}

void	ft_stos_null(char *f, char c, int *len)
{
	char	*s;

	s = NULL;
	if (c == 's')
		s = ft_strjoin(s, "(null)");
	else if (c == 'p' && NULL_OS == 2)
		s = ft_strjoin(s, "(nil)");
	else if (c == 'p' && NULL_OS == 1)
		s = ft_strjoin(s, "0x0");
	if (!s)
	{
		*len = -1;
		return ;
	}
	if (ft_strchr(f, '-') && ft_strchr(f, '.') && c != 'p')
		ft_display_l(f, s, len);
	else if (!ft_strchr(f, '-') && ft_strchr(f, '.') && c != 'p')
		ft_display_r(f, s, len);
	else if (!ft_strchr(f, '-') && (!ft_strchr(f, '.') || c == 'p'))
		ft_displayr(f, s, len);
	else if (ft_strchr(f, '-') && (!ft_strchr(f, '.') || c == 'p'))
		ft_displayl(f, s, len);
	free(s);
}
