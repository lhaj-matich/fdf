/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:46:50 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/08 15:49:48 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (size > 0)
		dst[i] = '\0';
	return (srclen);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

static int	ft_words(char const *s, char c)
{
	int	i;
	int	words;

	if (s[0] == '\0')
		return (0);
	words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			words++;
		i++;
	}
	if (s[i - 1] != c)
		words++;
	return (words);
}

static char	*next_word(char *str, char c, int *len)
{
	int		i;
	char	*tmp;
	int		count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == c)
		i++;
	tmp = &str[i];
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	*len = count;
	return (tmp);
}

static char	**ft_freetab(char **str, int tofree)
{
	while (--tofree >= 0)
		free(str[tofree]);
	free(str);
	str = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**str;
	char	*tmp;
	int		words;
	int		len;

	if (!s)
		return (NULL);
	i = -1;
	words = ft_words(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	tmp = (char *)s;
	len = 0;
	while (++i < words)
	{
		tmp = next_word(tmp + len, c, &len);
		str[i] = (char *)malloc(len + 1);
		if (!str[i])
			return (ft_freetab(str, i));
		ft_strlcpy(str[i], tmp, len + 1);
	}
	str[i] = 0;
	return (str);
}