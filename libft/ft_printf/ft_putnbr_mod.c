/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:23:26 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/09 11:13:42 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_sign(char *f, int n, int *len, int *count)
{
	if (n < 0)
	{
		ft_write('-', len);
		*count = *count + 1;
	}
	else if (ft_strchr(f, '+'))
	{
		ft_write('+', len);
		*count = *count + 1;
	}
	else if (ft_strchr(f, ' '))
	{
		ft_write(' ', len);
		*count = *count + 1;
	}
}

void	ft_putnbr_ull(unsigned long long nb, int *len)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (nb > 15)
	{
		ft_putnbr_ull(nb / 16, len);
		ft_putnbr_ull(nb % 16, len);
	}
	else
		ft_write(tab[nb], len);
}

void	ft_putnbr_uinthex(char *f, unsigned int nb, int *len)
{
	char	*tab;

	tab = NULL;
	if (nb > 15)
	{
		ft_putnbr_uinthex(f, nb / 16, len);
		ft_putnbr_uinthex(f, nb % 16, len);
	}
	else
	{
		if (f[ft_strlen(f) - 1] == 'x')
			tab = "0123456789abcdef";
		else
			tab = "0123456789ABCDEF";
		ft_write(tab[nb], len);
	}
}

void	ft_putnbr_mod(int nb, int *len)
{
	unsigned int	i;

	i = 0;
	if (nb < 0)
		i = -nb;
	else
		i = nb;
	if (i > 9)
	{
		ft_putnbr_mod(i / 10, len);
		ft_putnbr_mod(i % 10, len);
	}
	else
		ft_write(i + 48, len);
}

void	ft_putnbr_uint(unsigned int nb, int *len)
{
	if (nb > 9)
	{
		ft_putnbr_uint(nb / 10, len);
		ft_putnbr_uint(nb % 10, len);
	}
	else
		ft_write(nb + 48, len);
}
