/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:44:46 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/21 12:44:46 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	t;

	if (!str || !*str)
		return (str);
	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		t = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = t;
		i++;
	}
	return (str);
}
