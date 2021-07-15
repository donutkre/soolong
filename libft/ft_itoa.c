/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:01:58 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/05 22:33:59 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	all_num(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static int	nbr_g(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*make_str(int len, int nb, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * len + 1 + (nb < 0));
	if (dest)
	{
		if (n < 0)
		{
			dest[i] = '-';
			len++;
		}
		i = len - 1;
		while (nb >= 10)
		{
			dest[i] = nb % 10 + 48;
			nb /= 10;
			i--;
		}
		dest[i] = nb % 10 + 48;
		dest[len] = '\0';
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	nb;

	nb = nbr_g(n);
	len = all_num(nb);
	return (make_str(len, nb, n));
}
