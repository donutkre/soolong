/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:40:38 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/29 13:40:38 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i++;
		if (*s == '\0')
			i--;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static char	*ft_next(const char *s, char c)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i + len] && s[i + len] != c)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	j = 0;
	while (j < len)
	{
		str[j] = s[i + j];
		j++;
	}
	str[len] = '\0';
	return (str);
}

static int	strlen_init(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static void	ft_freee(char **a, int len)
{
	int		i;

	i = 0;
	while (i < len)
		if (a + i && a[i])
			free(a[i]);
	free(a);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (0);
	len = ft_wordlen((char *)s, c);
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		str = ft_next(s, c);
		if (!str)
		{
			ft_freee(arr, i);
			return (0);
		}
		arr[i++] = str;
		s += strlen_init(s, c) + ft_strlen(str);
	}
	arr[len] = 0;
	return (arr);
}
