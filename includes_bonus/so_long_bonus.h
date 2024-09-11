/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:04:51 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 14:03:47 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
//# include "../includes/mlx.h"
//# include <stdio.h>
//# include <strings.h>
//# include <stddef.h>
//# include <stdlib.h>
//# include <unistd.h>

# ifndef FRAME_TIME
#  define FRAME_TIME 18000
# endif

# ifndef LEFT
#  define LEFT 65361
# endif

# ifndef UP
#  define UP 65362
# endif

# ifndef RIGHT
#  define RIGHT 65363
# endif

# ifndef DOWN
#  define DOWN 65364
# endif

typedef struct s_biome
{
	int		x;
	int		y;
	int		start;
	int		exit;
	int		move;
	char	*cmove;
	void	*floor;
	void	*wall;
	void	*exit_open;
	void	*exit_closed;
}				t_biome;

typedef struct s_coins
{
	int		coinnum;
	int		coincheck;
	int		frame;
	void	*coin_1;
	void	*coin_2;
	void	*coin_3;
	void	*coin_4;
}				t_coins;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		is_there;
	char	dir;
	int		move_time;
	void	*enemy_u;
	void	*enemy_d;
	void	*enemy_l;
	void	*enemy_r;
}				t_enemy;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
	void	*player_u;
	void	*player_d;
	void	*player_l;
	void	*player_r;
	void	*player_eu;
	void	*player_ed;
	void	*player_el;
	void	*player_er;
}				t_player;

typedef struct s_data
{
	int			*errno;
	void		*mlx;
	int			width;
	int			height;
	void		*win;
	int			screen_x;
	int			screen_y;
	int			win_width;
	int			win_height;
	int			time;
	char		**map;
	char		**argv;
	t_player	*player;
	t_enemy		*enemy;
	t_coins		*coins;
	t_biome		*biome;
}				t_data;

// Initializations
void	init_coins(t_data *data);
void	init_biome(t_data *data);
void	init_player_exit_closed(t_data *data);
void	init_player(t_data *data);
void	init_enemy(t_data *data);
//	General logic and utils
int		key_hook(int keycode, t_data *data);
int		button_hook(t_data *data);
void	annihilate(t_data *data, char *message, int errno);
int		update_game(t_data *data);
size_t	ft_linelen_sl(char *str);
size_t	ft_arrlen(char	**arr);
int		find_char(char *s, char c);
void	ft_freecarr(char **arr);
void	exit_check(t_data *data);
void	reset_game(t_data *data);
void	good_game(t_data *data);
void	game_over(t_data *data);
int		update_game(t_data *data);
// Map utils
void	check_extension(t_data *data);
void	load_map(t_data *data);
int		validate_map(t_data *data);
int		find_path(t_data *data, int y, int x);
void	rectangle_check(t_data *data);
int		vertical_wall_check(t_data *data);
int		horizontal_wall_check(t_data *data);
void	get_coins(t_data *data);
void	get_positions(t_data *data);
// Enemy logic & movement
void	chase_on_x(t_data *data);
void	chase_on_y(t_data *data);
void	scan_for_player(t_data *data);
void	enemy_logic(t_data *data);
void	move_enemy_right(t_data *data);
void	move_enemy_up(t_data *data);
void	move_enemy_down(t_data *data);
void	move_enemy_left(t_data *data);
// Rendering kinda???
void	*image_check(t_data *data, char c);
void	next_frame(t_data *data);
void	*get_enemy_img(t_data *data);
void	*get_player_img(t_data *data);
void	*get_closed_exit_img(t_data *data);
void	*get_coin_img(t_data *data);

#endif 
