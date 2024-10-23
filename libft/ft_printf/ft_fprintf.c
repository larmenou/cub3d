/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 08:29:40 by bahommer          #+#    #+#             */
/*   Updated: 2023/03/20 09:24:52 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_arg_fd(int fd, char c, va_list *ptr, int *len)
{
	if (c == '%')
		ft_write('%', len);
	else if (c == 's')
		ft_stos_fd(fd, va_arg(*ptr, char *), len);
	else
		return ;
}

static int	ft_displaystr(int fd, const char *str, va_list *ptr, int *len)
{
	t_flags	s;

	s.i = 0;
	while (str[s.i])
	{
		s.j = 0;
		while (str[s.i + s.j] && str[s.i + s.j] != '%')
		{
			ft_write_fd(fd, str[s.i + s.j++], len);
			if (*len == -1)
				return (*len);
		}
		if (str[s.i + s.j])
		{
			ft_display_arg_fd(fd, str[s.i + ++s.j], ptr, len);
			if (*len == -1)
				return (-1);
			s.i = s.i + s. j + 1;
		}
		else
			s.i = s.i + s.j;
	}
	return (*len);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	if (!str)
		return (-1);
	va_start(ptr, str);
	ft_displaystr(fd, str, &ptr, &len);
	va_end(ptr);
	return (len);
}
