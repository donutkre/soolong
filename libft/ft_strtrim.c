/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:58:12 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/05 20:58:49 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*start;
	char	*end;
	char	*new_s;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = (char *)(s1 + ft_strlen(s1) - 1);
	while (end >= start && ft_strchr(set, *end))
		end--;
	new_s = ft_calloc(end - start + 2, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		*(new_s + i) = *(start + i);
		i++;
	}
	return (new_s);
}
