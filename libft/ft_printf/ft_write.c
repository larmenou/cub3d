/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:07:46 by bahommer          #+#    #+#             */
/*   Updated: 2023/03/20 08:34:16 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(char c, int *len)
{
	ssize_t	i;

	i = 0;
	if (*len != -1)
	{
		i = write(1, &c, 1);
		if (i == -1)
			*len = -1;
		else
			*len = *len + 1;
	}
}

void	ft_write_fd(int fd, char c, int *len)
{
	ssize_t	i;

	i = 0;
	if (*len != -1)
	{
		i = write(fd, &c, 1);
		if (i == -1)
			*len = -1;
		else
			*len = *len + 1;
	}
}

void	ft_putstr_mod(char *s, int *len)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		ft_write(s[i], len);
		if (*len == -1)
			return ;
	}
}

void	ft_hashtag(char *f, unsigned int n, int *i, int *len)
{
	if (n != 0)
	{
		if (f[ft_strlen(f) - 1] == 'x' && ft_strchr(f, '#'))
		{
			ft_putstr_mod("0x", len);
			*i = *i + 2;
		}
		else if (f[ft_strlen(f) - 1] == 'X' && ft_strchr(f, '#'))
		{
			ft_putstr_mod("0X", len);
			*i = *i + 2;
		}
	}
}
