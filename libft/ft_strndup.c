/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:46:57 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/21 12:46:57 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s)
{
	size_t	len;
	char	*d;

	len = ft_strlen(s) + 1;
	d = malloc(sizeof(char) * len);
	if (!d)
		return (NULL);
	return (ft_memcpy(d, s, len));
}
