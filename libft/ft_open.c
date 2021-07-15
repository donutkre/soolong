/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:16:07 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/11 20:27:57 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	ft_open(char *file)
{
	int	ret;

	ret = open(file, O_RDONLY);
	if (ret == -1)
		return (0);
	close(ret);
	return (1);
}
