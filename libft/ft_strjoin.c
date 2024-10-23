/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:25:58 by bahommer          #+#    #+#             */
/*   Updated: 2022/11/08 14:29:24 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	dst = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	if (dst == NULL)
		return (NULL);
	ft_strlcat(dst, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	return (dst);
}
