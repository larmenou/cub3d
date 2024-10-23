/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:34:47 by bahommer          #+#    #+#             */
/*   Updated: 2022/11/09 11:19:59 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = -1;
	if (!s || !f)
		return (NULL);
	dst = malloc(sizeof(*dst) * (ft_strlen(s) + 1));
	if (!dst)
		return (NULL);
	while (s[++i])
		dst[i] = f(i, s[i]);
	dst[i] = 0;
	return (dst);
}
