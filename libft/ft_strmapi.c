/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:13:04 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/05 21:29:24 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*arr;

	if (!s || !f)
		return (NULL);
	arr = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(arr + i) = f(i, *(s + i));
		i++;
	}
	return (arr);
}
