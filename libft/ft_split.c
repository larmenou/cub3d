/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:04:28 by bahommer          #+#    #+#             */
/*   Updated: 2023/03/03 19:55:25 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_wc(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i != 0 && s[i - 1] == c && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static int	ft_strncpy(char **tab, char *src, int j, int k)
{
	int	i;

	i = 0;
	tab[k] = malloc(sizeof(char) * (j + 1));
	if (!tab[k])
	{
		while (k >= 0)
		{
			free(tab[k]);
			k--;
		}
		free (tab);
		return (-1);
	}
	while (i < j && src[i] != '\0')
	{
		tab[k][i] = src[i];
		i++;
	}
	tab[k][i] = '\0';
	return (0);
}

static char	**ft_display_tab(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (s[++i])
	{
		if (s[i] == c || (i != 0 && s[i] != c && s[i - 1] != c))
			j = 0;
		else
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			if (ft_strncpy(tab, (char *)&s[i], j, k) == -1)
				return (NULL);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (ft_wc(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = ft_display_tab(tab, s, c);
	if (!tab)
		return (NULL);
	return (tab);
}
