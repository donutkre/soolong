/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:57:14 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/15 09:28:52 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
	Checks whether item has been picked
*/
static int	pick(t_game *game)
{
	t_data	*data;
	int		i;
	int		c;

	data = game->collect.c_s;
	i = game->collectable;
	c = 0;
	while (data)
	{
		if (data->eaten == 1)
			c++;
		data = data->col;
	}
	if (c == i)
		return (1);
	return (0);
}

/* 
	Checks for valid characters EPC210
*/
static void	valid_c(char c, t_game *game, char *d, int n)
{
	if (c == 'E')
		game->exit += 1;
	if (c == 'P')
		game->player += 1;
	if (c == 'C')
		game->collectable += 1;
	if (c == '2')
		game->enemyy += 1;
	if ((game->player > 1 || n == -1 || n == 0 || (!(c == '0' || c == '1'
					|| c == 'C' || c == 'E' || c == 'P' || c == '2')))
		&& c != '1')
	{
		free(d);
		error_message(game, "\033[0;31minvalid map\n");
	}
}

/* 
	Checks for player
*/
void	check_p(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->m_y / 64)
	{
		x = -1;
		while (++x < game->m_x / 64)
		{
			if (game->matrix[y][x] == 'P')
			{
				game->play.p_x = x;
				game->play.p_y = y;
			}
		}
	}
}

/* 
	Checks for item = player position.
*/
void	freedom(t_game *game, int y, int x)
{
	t_data	*data;

	game->play.o_x = game->play.p_x;
	game->play.o_y = game->play.p_y;
	game->play.p_y += y;
	game->play.p_x += x;
	game->count++;
	data = game->ext.e_s;
	while (data)
	{
		if (game->play.p_y == data->e_y && game->play.p_x == data->e_x)
		{
			if (pick(game) == 1)
			{
				game->won = WON;
				return ;
			}
		}
		data = data->ex;
	}
}

/* 
	Checks for North,East,South,West of map.
*/
void	checkwall(char *line, t_game *game, int n, int i)
{
	int	width;

	width = ft_strlen(line);
	i = -1;
	if (line[0] != '1' || line[width - 1] != '1')
	{
		free(line);
		error_message(game, "\033[0;31minvalid map\n");
	}
	while (line[++i])
		valid_c(line[i], game, line, n);
	game->m_x = i;
}
