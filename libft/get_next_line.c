/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:40:34 by bahommer          #+#    #+#             */
/*   Updated: 2023/02/28 11:16:51 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*to_free;

	to_free = s1;
	s1 = ft_strjoin(s1, s2);
	if (to_free)
		free(to_free);
	return (s1);
}

static char	*no_read(char *buf, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buf[i] != 0 && buf[i] != '\n')
		i++;
	i++;
	tmp = calloc(i + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, buf, i + 1);
	if (!tmp)
		return (NULL);
	line = ft_strjoin_free(line, tmp);
	free(tmp);
	if (!line)
		return (NULL);
	return (line);
}

static char	*get_line(char *buf, char *line, int fd)
{
	int		ret;

	if (buf[0] != 0)
	{
		line = ft_strjoin_free(line, buf);
		if (!line)
			return (NULL);
	}
	ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	if (ret == -1)
		return (NULL);
	while (ret != 0 && !ft_strchr(buf, '\n'))
	{
		line = ft_strjoin_free(line, buf);
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (ret == -1 || !line)
			return (NULL);
	}
	if (ret != 0)
		line = no_read(buf, line);
	if (!line)
		return (NULL);
	return (line);
}

static int	get_buf(char *buf)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	tmp = calloc(BUFFER_SIZE - i + 1, sizeof(char));
	if (!tmp)
		return (1);
	ft_strlcpy(tmp, &buf[i], ft_strlen(buf) - i + 1);
	ft_strlcpy(buf, tmp, ft_strlen(buf) - i + 1);
	free(tmp);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];

	line = NULL;
	if (fd > FOPEN_MAX || fd < 0)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	if (!ft_strchr(buf, '\n'))
	{
		line = get_line(buf, line, fd);
		if (!line)
			return (NULL);
	}
	else
		line = no_read(buf, line);
	if (!line)
		return (NULL);
	if (buf[0] != 0)
	{
		if (get_buf(buf) == 1)
			return (NULL);
	}		
	return (line);
}
