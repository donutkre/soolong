/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:08:36 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/30 18:08:36 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	i = 0;
	while (i < n && s[i] != (unsigned char)c)
	{
		d[i] = s[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		d[i] = s[i];
		i++;
		return (&d[i]);
	}
}
