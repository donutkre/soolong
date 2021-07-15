/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:56:36 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/15 09:25:13 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
	Clear memory and close app. 
*/
int	final_close(t_game *game)
{
	free_mem(game);
	ft_putstr("\033[0;33mBYE BYE\n");
	exit (0);
	return (0);
}

/* 
	Output steps in shell
*/
void	show_steps(t_game *game)
{
	char	*str;

	if (game->won != WON && game->lose != LOSE)
	{
		ft_putstr("\033[0;35msteps:\033[0;35m");
		ft_putstr(ft_itoa(game->count));
		ft_putstr("\n");
		str = ft_free(ft_itoa(game->count));
	}
}

/* 
	Get the game screen size.
*/
void	client_size(t_game *game)
{
	int	x;
	int	y;

	mlx_get_screen_size(game->addr, &x, &y);
	game->m_x *= 64;
	game->m_y *= 64;
}

/* 
	Output any error.
*/
int	error_message(t_game *game, char *c)
{
	ft_putstr(c);
	exit(1);
	return (0);
	(void)game;
}

/* 
	Big brain. no math require. change according to your xpm file size.
*/
void	algo(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	if (game->won != WON && game->lose != LOSE)
	{
		while (++y < game->m_y / 64)
		{
			x = -1;
			while (++x < game->m_x / 64)
				check_wall(game, y, x);
		}
	}
	else if (game->won == WON)
		mlx_string_put(game->addr, game->win, 105, 45, 0x000000FF, "YOU WIN!");
	else if (game->lose == LOSE)
		mlx_string_put(game->addr, game->win, 105, 45, 0x00FF0000, "YOU LOSE!");
}
