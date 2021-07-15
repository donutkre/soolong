/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 00:05:44 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/15 09:30:20 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	eaten(t_game *game, t_data *data)
{
	data = game->collect.c_s;
	while (game->collect.c_s)
	{
		if (game->play.p_y == data->c_y && game->play.p_x == data->c_x)
		{
			data->eaten = 1;
			return ;
		}
		data = data->col;
	}
}

static void	check_move(t_game *game, int i, int j, int count)
{
	t_data	*data;

	data = 0;
	if (count == 0)
	{
		freedom(game, i, j);
		show_steps(game);
	}
	if (count == 2)
	{
		game->play.p_y += i;
		game->play.p_x += j;
		game->count++;
		eaten(game, data);
		show_steps(game);
	}
	if (count == 3)
	{
		game->play.p_y += i;
		game->play.p_x += j;
		game->count++;
		game->lose = LOSE;
	}
}

/* 
	Checks if next move is blocked
*/
static int	check_next(t_game *game, int i, int j)
{
	if (game->matrix[game->play.p_y + i][game->play.p_x + j] == '1')
		return (WALL);
	if (game->matrix[game->play.p_y + i][game->play.p_x + j] == 'C')
		return (ITEM);
	if (game->matrix[game->play.p_y + i][game->play.p_x + j] == '2')
		return (ENEMY);
	return (1);
}

/* 
	This is where your high school geometry comes in.
*/
static void	coordinates(t_game *game, int x, int y)
{
	int	count;

	count = 0;
	if (check_next(game, x, y) == WALL)
		count = 1;
	else if (check_next(game, x, y) == ITEM)
		count = 2;
	else if (check_next(game, x, y) == ENEMY)
		count = 3;
	check_move(game, x, y, count);
}

/* 
	Checks for WASD key.
*/
int	key_control(int key, t_game *game)
{
	if (key == LEFT)
	{
		game->play.cord = 1;
		coordinates(game, 0, -1);
	}
	if (key == RIGHT)
	{
		game->play.cord = 2;
		coordinates(game, 0, 1);
	}
	if (key == UP)
	{
		game->play.cord = 3;
		coordinates(game, -1, 0);
	}
	if (key == DOWN)
	{
		game->play.cord = 4;
		coordinates(game, 1, 0);
	}
	if (key == ESC)
		final_close(game);
	return (0);
}
