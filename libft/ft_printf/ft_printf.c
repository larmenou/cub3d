/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:53:05 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/14 11:02:01 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg(char *str, va_list *ptr, int *len)
{
	if (str[ft_strlen(str) - 1] == '%')
		ft_write('%', len);
	if (str[ft_strlen(str) - 1] == 'c')
		ft_ctoc(str, va_arg(*ptr, int), len);
	else if (str[ft_strlen(str) - 1] == 's')
		ft_stos(str, va_arg(*ptr, char *), len);
	else if (str[ft_strlen(str) - 1] == 'p')
		ft_ptos(str, va_arg(*ptr, void *), len);
	else if (str[ft_strlen(str) - 1] == 'd' || str[ft_strlen(str) - 1] == 'i')
		ft_itos(str, va_arg(*ptr, int), len);
	else if (str[ft_strlen(str) - 1] == 'u')
		ft_utos(str, va_arg(*ptr, unsigned int), len);
	else if (str[ft_strlen(str) - 1] == 'x')
		ft_xtos(str, va_arg(*ptr, unsigned int), len);
	else if (str[ft_strlen(str) - 1] == 'X')
		ft_xtos(str, va_arg(*ptr, unsigned int), len);
}

static char	*ft_printarg(const char *str, size_t i, va_list *ptr, int *len)
{
	char	*flags;

	flags = ft_displayflags(str, i + 1, len);
	if (!flags)
	{
		*len = -1;
		return (NULL);
	}
	ft_display_arg(flags, ptr, len);
	return (flags);
}

static int	ft_displaystr(const char *str, va_list *ptr, int *len)
{
	t_flags	s;

	s.i = 0;
	s.tmp = NULL;
	while (str[s.i])
	{
		s.j = 0;
		while (str[s.i + s.j] && str[s.i + s.j] != '%')
		{
			ft_write(str[s.i + s.j++], len);
			if (*len == -1)
				return (*len);
		}
		if (str[s.i + s.j])
		{
			s.tmp = ft_printarg(str, s.i + s.j, ptr, len);
			if (!s.tmp || *len == -1)
				return (-1);
			s.i = s.i + s. j + ft_strlen(s.tmp) + 1;
			free(s.tmp);
		}
		else
			s.i = s.i + s.j;
	}
	return (*len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	if (!str)
		return (-1);
	va_start(ptr, str);
	ft_displaystr(str, &ptr, &len);
	va_end(ptr);
	return (len);
}
