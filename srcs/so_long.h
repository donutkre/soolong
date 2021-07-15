/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:03 by ktiong            #+#    #+#             */
/*   Updated: 2021/07/14 23:22:26 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define LEFT 97
# define RIGHT 100
# define UP 119
# define DOWN 115
# define ESC 65307
# define LOSE 699
# define WON 998
# define WALL -1
# define ITEM -11
# define ENEMY -111
# define G 0x0000FF00
# define START 0
# define RIGHT_IMG			"images/rightt.xpm"
# define LEFT_IMG			"images/leftt.xpm"
# define DOWN_IMG			"images/back.xpm"
# define UP_IMG			"images/frontt.xpm"
# define FLOOR_IMG			"images/flooor.xpm"
# define WALL_IMG			"images/wall.xpm"
# define COLLECT_IMG			"images/friess.xpm"
# define ENEMY_IMG			"images/enem.xpm"
# define DOOR_IMG			"images/door.xpm"

typedef struct s_data	t_data;

typedef struct s_data
{
	int				dead;
	int				en_x;
	int				en_y;
	t_data			*en;
	int				eaten;
	int				c_x;
	int				c_y;
	t_data			*col;
	int				e_x;
	int				e_y;
	t_data			*ex;
	t_data			*en_s;
	t_data			*c_s;
	t_data			*e_s;
	int				p_x;
	int				p_y;
	int				cord;
	int				o_x;
	int				o_y;
}				t_data;

typedef struct s_image
{
	void		*ptr;
	int			*mem;
	int			sl;
	int			bpp;
	int			ed;
	int			wth;
	int			hgt;
}				t_image;

typedef struct s_img
{
	char		*p_f;
	char		*p_w;
	char		*p_c;
	char		*rr;
	char		*ll;
	char		*dd;
	char		*uu;
	char		*dooor;
	char		*eee;
	t_image		m_f;
	t_image		m_w;
	t_image		m_c;
	t_image		m_rr;
	t_image		m_ll;
	t_image		m_dd;
	t_image		m_uu;
	t_image		m_eee;
	t_image		m_en;
}				t_img;

typedef struct s_game
{
	void		*addr;
	void		*win;
	int			player;
	int			exit;
	int			collectable;
	int			enemyy;
	int			m_x;
	int			m_y;
	char		**matrix;
	int			count;
	int			won;
	int			lose;
	t_image		image;
	t_img		store;
	t_data		play;
	t_data		ext;
	t_data		collect;
	t_data		enem;
}				t_game;

int				key_control(int key, t_game *game);
void			launch_map(t_game *game, char *map);
void			checkwall(char *line, t_game *game, int final, int i);
void			item_addr(t_game *game);
void			free_mem(t_game *game);
t_data			*check_item(t_game *game, t_data *data, int y, int x);
t_data			*check_en(t_game *game, t_data *data, int y, int x);
void			map_refresh_ex(t_game *game, int y, int x);
void			map_refreshitem(t_game *game, int y, int x);
void			map_refresh_en(t_game *game, int y, int x);
int				final_close(t_game *game);
void			show_steps(t_game *game);
void			client_size(t_game *game);
int				error_message(t_game *game, char *x);
void			check_wall(t_game *game, int x, int y);
void			check_p(t_game *game);
void			algo(t_game *game);
void			freedom(t_game *game, int y, int x);

#endif
