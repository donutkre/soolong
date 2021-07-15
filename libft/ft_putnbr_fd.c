/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:46:20 by ktiong            #+#    #+#             */
/*   Updated: 2021/04/30 18:46:20 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	c;

	sign = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		sign = -1;
	}
	if (n / 10)
		ft_putnbr_fd(n / 10 * sign, fd);
	c = (char)(n % 10 * sign + '0');
	write(fd, &c, 1);
}
