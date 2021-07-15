/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:11:14 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/30 21:11:14 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*c;
	t_list	*next;

	c = *lst;
	while (c)
	{
		next = c->next;
		ft_lstdelone(c, del);
		c = next;
	}
	*lst = NULL;
}
