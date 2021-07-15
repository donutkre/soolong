/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 00:50:33 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/15 01:06:14 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
	Essentially do your job, do what you should do. Calls for the function algo that checks for game status. 
*/
static int	do_your_job(t_game *game)
{
	algo(game);
	return (0);
}

/* 
	mlx_loop_hook() Keeps the program running even when there are no inputs (keyboard, mouse etc) and Continuously draws the screen based on the player's current location.
	mlx_hook() Major and powerful function that handles all inputs, but has no manual, Can receive key_press, key_release, mouse click, close button click, etc based on the x_event value
	mlx_loop() You have to hit this at the end to keep the program running without exiting. 
*/
static void	init_hooks(t_game game)
{
	mlx_loop_hook(game.addr, do_your_job, &game);
	mlx_hook(game.win, 2, (1L << 0), key_control, &game);
	mlx_hook(game.win, 17, (1L << 17), final_close, &game);
	mlx_loop(game.addr);
}

/* 
	mlx_new_window() creates a new window on the screen
	mlx_new_image()creates a new image in memory. It returns a Void *
	inits t_game structure with window and mlx_ptr 
*/
static void	init_window(t_game *game)
{
	game->win = mlx_new_window(game->addr, game->m_x, game->m_y, "So Long");
	game->image.ptr = mlx_new_image(game->addr, game->m_x, game->m_y);
}

/* 
	Checks for argument count, launch graphic, windows etc. 
*/
int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		error_message(&game, "\033[0;31m./so_long [map].ber\n");
	launch_map(&game, argv[1]);
	init_window(&game);
	init_hooks(game);
	return (0);
}
