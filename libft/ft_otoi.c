/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:05:25 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/21 13:05:25 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	cal(unsigned long long n)
{
	size_t	w;

	w = (n == 0);
	while (n)
	{
		n /= 8;
		w++;
	}
	return (w);
}

char	*ft_otoi(unsigned long long n)
{
	char			*num;
	int				rem;
	size_t			i;
	const size_t	w = cal(n);

	num = ft_calloc(w + 1, sizeof(char));
	if (!num)
		return (NULL);
	i = 0;
	while (i < w)
	{
		rem = n % 8;
		n = n / 8;
		num[i] = "01234567"[rem];
		i++;
	}
	return (ft_strrev(num));
}
