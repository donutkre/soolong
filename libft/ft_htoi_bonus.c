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

int	ft_htoi(char *s)
{
	int		dec;
	int		n;

	dec = 0;
	n = 0;
	if ('0' == *s && ('x' == *(s + 1) || 'X' == *(s + 1)))
	{
		s += 2;
	}
	while ('\0' != *s)
	{
		if (*s >= 'a' && *s <= 'f')
			return (n = *s - 'a' + 10);
		else if (*s >= 'A' && *s <= 'F')
			return (n = *s - 'A' + 10);
		else
			return (n = *s - '0');
		dec = dec * 16 + n;
		s++;
	}
	return (dec);
}
