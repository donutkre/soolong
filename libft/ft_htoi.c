/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:17:44 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/01 00:17:44 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static	size_t	cal(unsigned long long n)
{
	size_t	w;

	w = (n == 0);
	while (n)
	{
		n /= 16;
		w++;
	}
	return (w);
}

char	*ft_htoi(unsigned long long n, char s)
{
	char			*num;
	int				r;
	size_t			i;
	const size_t	w = cal(n);

	num = ft_calloc(w + 1, sizeof(char));
	if (!num)
		return (NULL);
	i = 0;
	while (i < w)
	{
		r = n % 16;
		n = n / 16;
		if (s == 'x')
			num[i] = "0123456789abcdef"[r];
		else
			num[i] = "0123456789ABCDEF"[r];
		i++;
	}
	return (ft_strrev(num));
}
