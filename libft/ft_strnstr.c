/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:09:46 by bahommer          #+#    #+#             */
/*   Updated: 2022/11/10 11:23:25 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] != needle[j] && j == 0)
			i++;
		else if (haystack[i + j] == needle[j] && needle[j] != '\0'
			&& i + j < len)
			j++;
		else if (needle[j] != '\0')
		{
			i++;
			j = 0;
		}
		else
			return ((char *)&haystack[i]);
	}
	return (0);
}
