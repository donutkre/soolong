/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:27:39 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/18 18:27:39 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_isnan(char c)
{
	char	*save;

	save = NULL;
	if (c == 'I')
		save = ft_strdup("-inf");
	if (c == 'i')
		save = ft_strdup("inf");
	if (c == 'n')
		save = ft_strdup("nan");
	return (save);
}
