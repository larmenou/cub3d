/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:49:51 by bahommer          #+#    #+#             */
/*   Updated: 2023/01/30 13:29:33 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n)
{
	int	digit;

	digit = 1;
	if (n < 0)
	{
		while (n < -9)
		{
			n /= 10;
			digit++;
		}	
	}
	else
	{
		while (n > 9)
		{
			n /= 10;
			digit++;
		}
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	nbr;
	char			*s;

	len = ft_digit(n);
	if (n < 0)
	{
		len++;
		nbr = -n;
	}
	else
		nbr = n;
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	while (len > 0 && s[len - 1] == 0)
	{
		s[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len --;
	}
	return (s);
}
