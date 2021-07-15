/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:41:06 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/15 09:27:02 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
	Initialize to 0 etc.
*/
static void	start_game(t_game *game, t_data *c, t_data *en, t_data *ex)
{
	game->player = START;
	game->exit = START;
	game->collectable = START;
	game->count = START;
	game->enemyy = START;
	game->play.cord = 4;
	c->c_s = START;
	en->en_s = START;
	ex->e_s = START;
}

/*
	checks the map requirements :
		-	1 starting point
		-	at least 1 exit
		-	at least 1 collectible
		-	wall surrounding the map
	if not output error message
*/

static void	valid_map(int fd, t_game *game, int i)
{
	char	*c;
	int		s;
	int		n;
	int		len;

	n = 0;
	i = -1;
	s = get_next_line(fd, &c);
	while (s)
	{
		len = ft_strlen(c);
		checkwall(c, game, n, i);
		n++;
		s = get_next_line(fd, &c);
	}
	game->m_y = n + 1;
	checkwall(c, game, -1, i);
	if ((game->exit == 0) || (game->player == 0) || (game->collectable == 0))
		error_message(game, "\033[0;31mMap error, no exit/item/player\n");
	free(c);
}

/* 
	Open and call get_next_line to read map.
*/
static void	print_map(int fd, char *map, t_game *game, int i)
{
	char	*c;
	int		s;

	c = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_message(game, "\033[0;31minvalid map\n");
	game->matrix = ft_calloc(1, (game->m_y * game->m_x) + 30);
	i = 0;
	if (game->m_x > 1 && game->m_y > 1)
	{
		s = get_next_line(fd, &c);
		while (s)
		{
			game->matrix[i] = ft_strndup(c);
			i++;
			c = ft_free(c);
			s = get_next_line(fd, &c);
		}
		game->matrix[i] = ft_strndup(c);
		c = ft_free(c);
	}
	close(fd);
}

/* 
	Calls for client size, image addr and check for valid pandas.
*/
static void	init_pas(t_game *game)
{
	game->addr = mlx_init();
	client_size(game);
	item_addr(game);
	check_p(game);
}

/* 
	This is it. time to shine.
*/
void	launch_map(t_game *game, char *map)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_message(game, "\033[0;31minvalid map\n");
	start_game(game, &game->collect, &game->enem, &game->ext);
	valid_map(fd, game, i);
	print_map(fd, map, game, i);
	init_pas(game);
	close(fd);
}
