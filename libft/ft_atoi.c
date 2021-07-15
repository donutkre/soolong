/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:12:08 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/30 17:12:08 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	value(int n)
{
	if (n == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *nbr)
{
	int		sign;
	int		i;
	long	num;
	long	max;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nbr[i]) == 1)
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
		if (nbr[i++] == '-')
			sign = -1;
	max = LONG_MAX / 10;
	while (ft_isdigit(nbr[i]) == 1)
	{
		if (num > max)
			return (value(sign));
		num = (num * 10) + (nbr[i] - '0');
		if (num < 0)
			return (value(sign));
		i++;
	}
	return ((int)(num * sign));
}
