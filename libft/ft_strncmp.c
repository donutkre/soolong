/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:44:37 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/02 19:40:45 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		j = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (j)
			return (j);
		i++;
	}
	return (0);
}
