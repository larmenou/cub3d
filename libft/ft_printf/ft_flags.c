/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:02:24 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/06 11:29:52 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char c)
{
	if (c == '#' || c == '-' || c == ' ' || c == '+' || c == '0')
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	else if (c == '.')
		return (3);
	else if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (4);
	else
		return (0);
}

int	ft_zeroisflag(char *flags)
{
	int	i;

	i = 0;
	while (flags[i] && ft_isflag(flags[i]) == 1)
	{
		if (flags[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_printflags(const char *str, int i, int j, int *len)
{
	char	*flags;
	int		k;

	k = 0;
	flags = ft_calloc(j + 1, sizeof(char));
	if (!flags)
		return (NULL);
	ft_write(str[i - 1], len);
	while (j >= 0)
	{
		ft_write(str[i], len);
		if (*len == -1)
			return (NULL);
		flags[k] = str[i];
		i++;
		k++;
		j--;
	}
	return (flags);
}

char	*ft_displayflags(const char *str, size_t i, int *len)
{
	size_t	j;
	char	*flags;

	j = 0;
	flags = NULL;
	while (str[i + j] && (ft_isflag(str[i + j]) == 1))
		j++;
	while (str[i + j] && (ft_isflag(str[i + j]) == 2 || str[i + j] == '0'))
		j++;
	if (str[i + j] && (ft_isflag(str[i + j]) == 3))
		j++;
	while (str[i + j] && (ft_isflag(str[i + j]) == 2 || str[i + j] == '0'))
		j++;
	if (ft_isflag(str[i + j]) == 4)
	{
		j++;
		flags = ft_calloc(j + 1, sizeof(char));
		if (!flags)
			return (NULL);
		ft_strlcpy(flags, &str[i], j + 1);
		return (flags);
	}
	else
		return (ft_printflags(str, i, j, len));
}
