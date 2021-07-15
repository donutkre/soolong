/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:46:43 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/29 13:46:43 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (*dst != 0 && len < dstsize)
	{
		len++;
		dst++;
	}
	while (*src != 0 && len + 1 < dstsize)
	{
		*dst++ = *src++;
		len++;
	}
	if (len < dstsize)
		*dst = 0;
	while (*src++ != 0)
		len++;
	return (len);
}
