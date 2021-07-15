/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:58:58 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/19 01:58:58 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *s, size_t max_len, int fd)
{
	size_t	s_len;

	if (s)
	{
		s_len = ft_strlen(s);
		if (s_len > max_len)
			write(fd, s, max_len);
		else
			write(fd, s, s_len);
	}
}

void	ft_putfstr_fd(char *s, size_t len, int fd)
{
	if (s)
		write(fd, s, len);
}
