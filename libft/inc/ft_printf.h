/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:42:38 by bahommer          #+#    #+#             */
/*   Updated: 2023/03/20 09:25:24 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

typedef struct s_flags
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	c;
	char	*line;
	char	*tmp;
	int		len;
}	t_flags;

# ifdef __APPLE__
#  define NULL_OS 1
# else
#  define NULL_OS 2
# endif

int		ft_printf(const char *str, ...);
int		ft_fprintf(int fd, const char *str, ...);

int		ft_atoi(const char *str);
int		ft_isflag(char c);
int		ft_zeroisflag(char *flags);
int		ft_dotisok(char *flags);
int		ft_digit(int n);
int		ft_digit_uint(unsigned int n);
int		ft_digit_hex(unsigned long long n);
int		ft_digit_uihex(unsigned int n);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*ft_strchr(const char *s, int c);
char	*ft_displayflags(const char *str, size_t i, int *len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_printflags(const char *str, int i, int j, int *len);
char	*ft_displayflags(const char *str, size_t i, int *len);

void	*ft_calloc(size_t count, size_t size);

void	ft_display_arg(char *str, va_list *ptr, int *len);
void	ft_write(char c, int *len);
void	ft_write_fd(int fd, char c, int *len);
void	ft_putstr_mod(char *s, int *len);
void	ft_putnbr_mod(int nb, int *len);
void	ft_write_sign(char *f, int n, int *len, int *count);
void	ft_putnbr_uint(unsigned int nb, int *len);
void	ft_hashtag(char *f, unsigned int n, int *i, int *len);
void	ft_putnbr_ull(unsigned long long nb, int *len);
void	ft_putnbr_uinthex(char *f, unsigned int nb, int *len);

void	ft_ctoc(char *f, unsigned char c, int *len);
void	ft_stos(char *f, char *str, int *len);
void	ft_stos_fd(int fd, char *str, int *len);
void	ft_stos_null(char *f, char c, int *len);
void	ft_ptos(char *f, void *ptr, int *len);
void	ft_itos(char *f, int n, int *len);
void	ft_utos(char *f, unsigned int n, int *len);
void	ft_xtos(char *f, unsigned int n, int *len);

#endif
