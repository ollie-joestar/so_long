/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annihilate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:04:33 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 14:02:24 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static void	destroy_enemy(t_data *data)
{
	if (data->enemy->enemy_d)
		mlx_destroy_image(data->mlx, data->enemy->enemy_d);
	if (data->enemy->enemy_r)
		mlx_destroy_image(data->mlx, data->enemy->enemy_r);
	if (data->enemy->enemy_l)
		mlx_destroy_image(data->mlx, data->enemy->enemy_l);
	if (data->enemy->enemy_u)
		mlx_destroy_image(data->mlx, data->enemy->enemy_u);
	free(data->enemy);
}

static void	destroy_player(t_data *data)
{
	if (data->player->player_d)
		mlx_destroy_image(data->mlx, data->player->player_d);
	if (data->player->player_r)
		mlx_destroy_image(data->mlx, data->player->player_r);
	if (data->player->player_l)
		mlx_destroy_image(data->mlx, data->player->player_l);
	if (data->player->player_u)
		mlx_destroy_image(data->mlx, data->player->player_u);
	if (data->player->player_ed)
		mlx_destroy_image(data->mlx, data->player->player_ed);
	if (data->player->player_er)
		mlx_destroy_image(data->mlx, data->player->player_er);
	if (data->player->player_el)
		mlx_destroy_image(data->mlx, data->player->player_el);
	if (data->player->player_eu)
		mlx_destroy_image(data->mlx, data->player->player_eu);
	free(data->player);
}

static void	destroy_coins(t_data *data)
{
	if (data->coins->coin_1)
		mlx_destroy_image(data->mlx, data->coins->coin_1);
	if (data->coins->coin_2)
		mlx_destroy_image(data->mlx, data->coins->coin_2);
	if (data->coins->coin_3)
		mlx_destroy_image(data->mlx, data->coins->coin_3);
	if (data->coins->coin_4)
		mlx_destroy_image(data->mlx, data->coins->coin_4);
	free(data->coins);
}

static void	destroy_biome(t_data *data)
{
	if (data->biome->floor)
		mlx_destroy_image(data->mlx, data->biome->floor);
	if (data->biome->wall)
		mlx_destroy_image(data->mlx, data->biome->wall);
	if (data->biome->exit_open)
		mlx_destroy_image(data->mlx, data->biome->exit_open);
	if (data->biome->exit_closed)
		mlx_destroy_image(data->mlx, data->biome->exit_closed);
	if (data->biome->cmove)
		free(data->biome->cmove);
	free(data->biome);
}

void	annihilate(t_data *data, char *message, int errno)
{
	if (message && message[0])
		ft_printf("%s", message);
	if (data)
	{
		if (data->enemy)
			destroy_enemy(data);
		if (data->player)
			destroy_player(data);
		if (data->coins)
			destroy_coins(data);
		if (data->biome)
			destroy_biome(data);
		if (data->win)
		{
			mlx_clear_window(data->mlx, data->win);
			mlx_destroy_window(data->mlx, data->win);
		}
		if (data->mlx)
			mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_freecarr(data->map);
	}
	free(data);
	exit(errno);
}
