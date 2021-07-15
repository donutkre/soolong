/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:10:58 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/30 21:10:58 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*c;

	if (!lst)
		return ;
	if (*lst)
	{
		c = *lst;
		while (c->next)
			c = c->next;
		c->next = new;
	}
	else
		*lst = new;
}
