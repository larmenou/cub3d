/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:50:45 by bahommer          #+#    #+#             */
/*   Updated: 2022/11/02 20:04:53 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (ft_strlen(&s[start]) < len)
		dst = malloc(sizeof(*dst) * (ft_strlen(&s[start]) + 1));
	else
		dst = malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s[start], len + 1);
	if (!dst)
		return (NULL);
	return (dst);
}
