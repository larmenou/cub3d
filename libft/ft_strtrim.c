/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:31:12 by bahommer          #+#    #+#             */
/*   Updated: 2022/11/09 15:01:10 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (ft_isset(s1[i], set) && s1[i])
		i++;
	while (j < ft_strlen(s1) && ft_isset(s1[ft_strlen(s1) - j - 1], set))
		j++;
	if (i != ft_strlen(s1))
		dst = malloc(sizeof(*dst) * (ft_strlen(s1) - i - j + 1));
	else
		dst = malloc(sizeof(*dst));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s1[i], ft_strlen(s1) - i - j + 1);
	if (!dst)
		return (NULL);
	return (dst);
}
