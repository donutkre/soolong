/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:33:39 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/14 23:22:35 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*check_item(t_game *game, t_data *data, int y, int x)
{
	data = game->collect.c_s;
	while (data)
	{
		if (data->c_y == y && data->c_x == x)
			return (data);
		data = data->col;
	}
	return (0);
}

t_data	*check_en(t_game *game, t_data *data, int y, int x)
{
	data = game->enem.en_s;
	while (data)
	{
		if (data->en_y == y && data->en_x == x)
			return (data);
		data = data->en;
	}
	return (0);
}

void	map_refreshitem(t_game *game, int y, int x)
{
	t_data	*data;
	t_data	*store;

	data = malloc(sizeof(t_data));
	data->c_y = y;
	data->c_x = x;
	data->eaten = 0;
	if (!game->collect.c_s)
	{
		data->col = 0;
		game->collect.c_s = data;
		return ;
	}
	store = game->collect.c_s;
	while (store->col)
		store = store->col;
	store->col = data;
	data->col = 0;
}

void	map_refresh_en(t_game *game, int y, int x)
{
	t_data	*data;
	t_data	*store;

	data = malloc(sizeof(t_data));
	data->en_y = y;
	data->en_x = x;
	data->dead = 0;
	if (!game->enem.en_s)
	{
		data->en = 0;
		game->enem.en_s = data;
		return ;
	}
	store = game->enem.en_s;
	while (store->en)
		store = store->en;
	store->en = data;
	data->en = 0;
}

void	map_refresh_ex(t_game *game, int y, int x)
{
	t_data	*data;
	t_data	*store;

	data = malloc(sizeof(t_data));
	data->e_y = y;
	data->e_x = x;
	if (!game->ext.e_s)
	{
		data->ex = 0;
		game->ext.e_s = data;
		return ;
	}
	store = game->ext.e_s;
	while (store->ex)
		store = store->ex;
	store->ex = data;
	data->ex = 0;
}
