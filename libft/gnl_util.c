/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:18:45 by ktiong            #+#    #+#             */
/*   Updated: 2021/06/10 10:28:34 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;
	const char	*c;

	if (!dst || !src)
		return (0);
	len = size;
	c = src;
	if (size != 0)
	{
		while (--len && *src)
			*dst++ = *src++;
		if (len)
			*dst++ = *src++;
	}
	if (len == 0 && size != 0)
		*dst = '\0';
	return (gnl_strlen(c));
}

char	*gnl_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	*p;
	unsigned char	str;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = (unsigned char *)s;
	len = gnl_strlen(s);
	str = (unsigned char)c;
	while (i <= len)
	{
		if (*p == str)
			return ((void *)p);
		i++;
		p++;
	}
	return (NULL);
}

char	*gnl_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = gnl_strlen((char *)s1);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*gnl_strjoin(char *s1, char *s2, ssize_t num_read)
{
	size_t	i;
	size_t	j;
	char	*str;

	s2[num_read] = '\0';
	if (!s1)
		return (gnl_strdup(s2));
	str = gnl_calloc(gnl_strlen(s1) + gnl_strlen(s2) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}
