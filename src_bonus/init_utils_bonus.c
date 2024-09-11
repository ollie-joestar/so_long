/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:37:16 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 14:02:16 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	init_coins(t_data *data)
{
	t_coins	*coins;

	coins = ft_calloc(sizeof(t_coins), 1);
	if (!coins)
		annihilate(data, "Error\nFailed to alloc coins\n", 1);
	data->coins = coins;
	coins->frame = 1;
	coins->coin_1 = mlx_xpm_file_to_image(data->mlx,
			"textures/coin_1.xpm", &data->width, &data->height);
	if (!coins->coin_1)
		annihilate(data, "Error\nFailed to load coin img\n", 1);
	coins->coin_2 = mlx_xpm_file_to_image(data->mlx,
			"textures/coin_2.xpm", &data->width, &data->height);
	if (!coins->coin_2)
		annihilate(data, "Error\nFailed to load coin img\n", 1);
	coins->coin_3 = mlx_xpm_file_to_image(data->mlx,
			"textures/coin_3.xpm", &data->width, &data->height);
	if (!coins->coin_3)
		annihilate(data, "Error\nFailed to load coin img\n", 1);
	coins->coin_4 = mlx_xpm_file_to_image(data->mlx,
			"textures/coin_4.xpm", &data->width, &data->height);
	if (!coins->coin_4)
		annihilate(data, "Error\nFailed to load coin img\n", 1);
}

void	init_biome(t_data *data)
{
	t_biome	*biome;

	biome = ft_calloc(sizeof(t_biome), 1);
	if (!biome)
		annihilate(data, "Error\nFailed to alloc biome\n", 1);
	data->biome = biome;
	biome->floor = mlx_xpm_file_to_image(data->mlx,
			"textures/floor.xpm", &data->width, &data->height);
	if (!biome->floor)
		annihilate(data, "Error\nFailed to load floor\n", 1);
	biome->wall = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &data->width, &data->height);
	if (!biome->wall)
		annihilate(data, "Error\nFailed to load wall\n", 1);
	biome->exit_open = mlx_xpm_file_to_image(data->mlx,
			"textures/exito.xpm", &data->width, &data->height);
	if (!biome->exit_open)
		annihilate(data, "Error\nFailed to load exit img\n", 1);
	biome->exit_closed = mlx_xpm_file_to_image(data->mlx,
			"textures/exitc.xpm", &data->width, &data->height);
	if (!biome->exit_closed)
		annihilate(data, "Error\nFailed to load exit img\n", 1);
}

void	init_player_exit_closed(t_data *data)
{
	data->player->player_eu = mlx_xpm_file_to_image(data->mlx,
			"textures/player_eu.xpm", &data->width, &data->height);
	if (!data->player->player_eu)
		annihilate(data, "Error\nFailed to load player img", 1);
	data->player->player_ed = mlx_xpm_file_to_image(data->mlx,
			"textures/player_ed.xpm", &data->width, &data->height);
	if (!data->player->player_ed)
		annihilate(data, "Error\nFailed to load player img", 1);
	data->player->player_el = mlx_xpm_file_to_image(data->mlx,
			"textures/player_el.xpm", &data->width, &data->height);
	if (!data->player->player_el)
		annihilate(data, "Error\nFailed to load player img", 1);
	data->player->player_er = mlx_xpm_file_to_image(data->mlx,
			"textures/player_er.xpm", &data->width, &data->height);
	if (!data->player->player_er)
		annihilate(data, "Error\nFailed to load player img", 1);
}

void	init_player(t_data *data)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		annihilate(data, "Error\nFailed to alloc player", 1);
	data->player = player;
	player->dir = 'd';
	player->player_u = mlx_xpm_file_to_image(data->mlx, "textures/player_u.xpm",
			&data->width, &data->height);
	if (!player->player_u)
		annihilate(data, "Error\nFailed to load player img", 1);
	player->player_d = mlx_xpm_file_to_image(data->mlx, "textures/player_d.xpm",
			&data->width, &data->height);
	if (!player->player_d)
		annihilate(data, "Error\nFailed to load player img", 1);
	player->player_l = mlx_xpm_file_to_image(data->mlx, "textures/player_l.xpm",
			&data->width, &data->height);
	if (!player->player_l)
		annihilate(data, "Error\nFailed to load player img", 1);
	player->player_r = mlx_xpm_file_to_image(data->mlx, "textures/player_r.xpm",
			&data->width, &data->height);
	if (!player->player_r)
		annihilate(data, "Error\nFailed to load player img", 1);
	init_player_exit_closed(data);
}

void	init_enemy(t_data *data)
{
	t_enemy	*enemy;

	enemy = ft_calloc(sizeof(t_enemy), 1);
	if (!enemy)
		annihilate(data, "Error\nFailed to alloc enemy\n", 1);
	data->enemy = enemy;
	enemy->move_time = 0;
	enemy->dir = 'u';
	enemy->enemy_u = mlx_xpm_file_to_image(data->mlx, "textures/enemy_u.xpm",
			&data->width, &data->height);
	if (!enemy->enemy_u)
		annihilate(data, "Error\nFailed to load enemy img", 1);
	enemy->enemy_d = mlx_xpm_file_to_image(data->mlx, "textures/enemy_d.xpm",
			&data->width, &data->height);
	if (!enemy->enemy_d)
		annihilate(data, "Error\nFailed to load enemy img", 1);
	enemy->enemy_l = mlx_xpm_file_to_image(data->mlx, "textures/enemy_l.xpm",
			&data->width, &data->height);
	if (!enemy->enemy_l)
		annihilate(data, "Error\nFailed to load enemy img", 1);
	enemy->enemy_r = mlx_xpm_file_to_image(data->mlx, "textures/enemy_r.xpm",
			&data->width, &data->height);
	if (!enemy->enemy_r)
		annihilate(data, "Error\nFailed to load enemy img", 1);
}
