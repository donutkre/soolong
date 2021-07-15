/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:40:41 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/20 20:40:41 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_tern(int c, long c1, long c2)
{
	if (c)
		return (c1);
	else
		return (c2);
}

char	ft_ternc(int c, char c1, char c2)
{
	if (c)
		return (c1);
	else
		return (c2);
}

long long	ft_ternl(int c, long long c1, long long c2)
{
	if (c)
		return (c1);
	else
		return (c2);
}

long double	ft_ternf(int c, long double c1, long double c2)
{
	if (c)
		return (c1);
	else
		return (c2);
}

void	*ft_ternp(int c, void *c1, void *c2, short tofree)
{
	if (c)
	{
		if (tofree)
			free(c2);
		return (c1);
	}
	else
	{
		if (tofree)
			free(c1);
		return (c2);
	}
}
