/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:44:03 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/05 21:19:46 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	char			*d;

	if (!s1 || !s2)
		return (NULL);
	d = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (*s1)
		d[i++] = *s1++;
	while (*s2)
		d[i++] = *s2++;
	d[i] = '\0';
	return (d);
}
