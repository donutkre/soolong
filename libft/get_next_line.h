/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:19:29 by ktiong            #+#    #+#             */
/*   Updated: 2021/06/08 12:43:31 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

void	*gnl_memset(void *s, int c, size_t n);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strjoin(char *s1, char *s2, ssize_t num_read);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s1);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *s);
int		get_next_line(int fd, char **line);

#endif