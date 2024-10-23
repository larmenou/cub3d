/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:47:40 by bahommer          #+#    #+#             */
/*   Updated: 2022/10/27 10:23:13 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc(sizeof(*dest) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	return (dest);
}
