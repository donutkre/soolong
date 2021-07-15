/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:50:20 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/29 13:50:20 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	i;
	size_t	arr;

	last = (char *)s;
	i = (char)c;
	arr = ft_strlen(s);
	while (arr > 0)
	{
		if (last[arr] == i)
			return (last + arr);
		arr--;
	}
	if (last[arr] == i)
		return (last);
	return (0);
}
