/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:42:12 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/15 00:57:08 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	use mlx_destroy_image in order to close the game properly
*/

void	free_mem(t_game *game)
{
	if (game->store.m_c.ptr)
		mlx_destroy_image(game->addr, game->store.m_c.ptr);
	if (game->store.m_eee.ptr)
		mlx_destroy_image(game->addr, game->store.m_eee.ptr);
	if (game->store.m_f.ptr)
		mlx_destroy_image(game->addr, game->store.m_f.ptr);
	if (game->store.m_rr.ptr)
		mlx_destroy_image(game->addr, game->store.m_rr.ptr);
	if (game->store.m_ll.ptr)
		mlx_destroy_image(game->addr, game->store.m_ll.ptr);
	if (game->store.m_dd.ptr)
		mlx_destroy_image(game->addr, game->store.m_dd.ptr);
	if (game->store.m_uu.ptr)
		mlx_destroy_image(game->addr, game->store.m_uu.ptr);
	if (game->store.m_w.ptr)
		mlx_destroy_image(game->addr, game->store.m_w.ptr);
	if (game->store.m_en.ptr)
		mlx_destroy_image(game->addr, game->store.m_en.ptr);
}

/*
	renders each frame
*/
static void	initialize_player(t_game *game, int y, int x)
{
	if (game->play.cord == 1 && x == game->play.p_x && y == game->play.p_y)
		mlx_put_image_to_window(game->addr, game->win, game->store.m_ll.ptr,
			game->store.m_ll.wth * x, game->store.m_ll.hgt * y);
	if (game->play.cord == 2 && x == game->play.p_x && y == game->play.p_y)
		mlx_put_image_to_window(game->addr, game->win, game->store.m_rr.ptr,
			game->store.m_rr.wth * x, game->store.m_rr.hgt * y);
	if (game->play.cord == 3 && x == game->play.p_x && y == game->play.p_y)
		mlx_put_image_to_window(game->addr, game->win, game->store.m_dd.ptr,
			game->store.m_dd.wth * x, game->store.m_dd.hgt * y);
	if (game->play.cord == 4 && x == game->play.p_x && y == game->play.p_y)
		mlx_put_image_to_window(game->addr, game->win, game->store.m_uu.ptr,
			game->store.m_uu.wth * x, game->store.m_uu.hgt * y);
}

/*
	checks for 'C' '2', item & enemy
*/
static void	valid_item(t_game *game, int y, int x)
{
	t_data	*data;

	data = 0;
	if (game->matrix[y][x] == 'C')
	{
		map_refreshitem(game, y, x);
		if (check_item(game, data, y, x) && check_item(game, data, y, x)
			->eaten == 0)
			mlx_put_image_to_window(game->addr, game->win, game->store.m_c.ptr,
				game->store.m_c.wth * x, game->store.m_c.hgt * y);
	}
	if (game->matrix[y][x] == '2')
	{
		map_refresh_en(game, y, x);
		if (check_en(game, data, y, x) && check_en(game, data, y, x)
			->dead == 0)
			mlx_put_image_to_window(game->addr, game->win, game->store.m_en.ptr,
				game->store.m_en.wth * x, game->store.m_en.hgt * y);
	}
}

/*
	checks for '1' 'E', wall & exit line 94 will print out the background and refresh everytime. And checks for valid item, display the biggest text on screen -_-
*/
void	check_wall(t_game *game, int y, int x)
{	
	if (game->matrix[y][x] == '1')
		mlx_put_image_to_window(game->addr, game->win, game->store.m_w.ptr,
			game->store.m_w.wth * x, game->store.m_w.hgt * y);
	else
		mlx_put_image_to_window(game->addr, game->win, game->store.m_f.ptr,
			game->store.m_f.wth * x, game->store.m_f.hgt * y);
	if (game->matrix[y][x] == 'E')
	{
		map_refresh_ex(game, y, x);
		mlx_put_image_to_window(game->addr, game->win, game->store.m_eee.ptr,
			game->store.m_eee.wth * x, game->store.m_eee.hgt * y);
	}
	valid_item(game, y, x);
	initialize_player(game, y, x);
	mlx_string_put(game->addr, game->win, 105, 20, G, "STEPS:");
	mlx_string_put(game->addr, game->win, 150, 20, G, ft_itoa(game->count));
}

/* 
	get textures from xpm files 
*/
void	item_addr(t_game *game)
{
	game->store.m_rr.ptr = mlx_xpm_file_to_image(game->addr,
			RIGHT_IMG, &game->store.m_rr.wth, &game->store.m_rr.hgt);
	game->store.m_ll.ptr = mlx_xpm_file_to_image(game->addr,
			LEFT_IMG, &game->store.m_ll.wth, &game->store.m_ll.hgt);
	game->store.m_dd.ptr = mlx_xpm_file_to_image(game->addr,
			DOWN_IMG, &game->store.m_dd.wth, &game->store.m_dd.hgt);
	game->store.m_uu.ptr = mlx_xpm_file_to_image(game->addr,
			UP_IMG, &game->store.m_uu.wth, &game->store.m_uu.hgt);
	game->store.m_f.ptr = mlx_xpm_file_to_image(game->addr,
			FLOOR_IMG, &game->store.m_f.wth, &game->store.m_f.hgt);
	game->store.m_w.ptr = mlx_xpm_file_to_image(game->addr,
			WALL_IMG, &game-> store.m_w.wth, &game->store.m_w.hgt);
	game->store.m_c.ptr = mlx_xpm_file_to_image(game->addr,
			COLLECT_IMG, &game->store.m_c.wth, &game->store.m_c.hgt);
	game->store.m_eee.ptr = mlx_xpm_file_to_image(game->addr,
			DOOR_IMG, &game->store.m_eee.wth, &game->store.m_eee.hgt);
	game->store.m_en.ptr = mlx_xpm_file_to_image(game->addr,
			ENEMY_IMG, &game->store.m_en.wth, &game->store.m_en.hgt);
}
