/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:22:06 by bahommer          #+#    #+#             */
/*   Updated: 2022/12/08 14:27:43 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit(int n)
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

int	ft_digit_uint(unsigned int n)
{
	int	digit;

	digit = 1;
	while (n > 9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

int	ft_digit_hex(unsigned long long n)
{
	int	digit;

	digit = 1;
	while (n > 15)
	{
		n /= 16;
		digit++;
	}
	return (digit);
}

int	ft_digit_uihex(unsigned int n)
{
	int	digit;

	digit = 1;
	while (n > 15)
	{
		n /= 16;
		digit++;
	}
	return (digit);
}
