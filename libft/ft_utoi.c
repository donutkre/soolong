/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:00:54 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/21 13:00:54 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	cal(unsigned long long n)
{
	size_t	w;

	w = (n == 0);
	while (n)
	{
		n /= 10;
		w++;
	}
	return (w);
}

char	*ft_utoi(unsigned long long n)
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
		r = n % 10;
		n = n / 10;
		num[i] = "0123456789"[r];
		i++;
	}
	return (ft_strrev(num));
}
