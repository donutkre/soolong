/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:30:56 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/11 20:30:58 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = (unsigned char)c;
	return (s);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = count * size;
	ptr = malloc(i);
	if (ptr)
		gnl_memset(ptr, 0, i);
	return (ptr);
}

int	read_buf(int fd, char **backup)
{
	char		*buf;
	ssize_t		read_size;

	read_size = BUFFER_SIZE;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	while (gnl_strchr(*backup, '\n') == NULL && read_size == BUFFER_SIZE)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			break ;
		*backup = gnl_strjoin(*backup, buf, read_size);
		if (*backup == NULL)
		{
			read_size = -1;
			break ;
		}
	}
	free(buf);
	if (read_size < 0)
		return (-1);
	if (gnl_strchr(*backup, '\n') != NULL)
		return (1);
	return (0);
}

char	*next_line(char **backup)
{
	char		*line;
	char		*tmp;
	char		*newline;

	newline = gnl_strchr(*backup, '\n');
	if (newline == NULL)
	{
		tmp = gnl_strdup(*backup);
		free(*backup);
		*backup = NULL;
		return (tmp);
	}
	line = (char *)malloc(sizeof(char) * (newline - *backup + 1));
	if (!line)
		return (NULL);
	gnl_strlcpy(line, *backup, newline - *backup + 1);
	tmp = *backup;
	*backup = gnl_strdup(++newline);
	if (*backup == NULL)
		return (NULL);
	free(tmp);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*s[OPEN_MAX];
	int			n;

	n = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (-1);
	if (gnl_strchr(s[fd], '\n') == NULL)
	{
		n = read_buf(fd, &s[fd]);
		if (n == -1)
			return (-1);
	}
	if ((n == 1) || (n == 0))
	{
		*line = next_line(&s[fd]);
		if (*line == NULL)
			return (-1);
	}
	return (n);
}
