/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:46:20 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 15:36:32 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_check(t_data *data)
{
	if (data->coins->coincheck == 0)
	{
		data->map[data->biome->y][data->biome->x] = 'F';
		if (data->biome->y == data->player->y && \
			data->biome->x == data->player->x)
			good_game(data);
	}
	if (data->coins->coincheck != 0)
	{
		data->map[data->biome->y][data->biome->x] = 'E';
		if (data->biome->y == data->player->y && \
			data->biome->x == data->player->x)
			data->map[data->biome->y][data->biome->x] = 'e';
	}
}
/**/
/*void	reset_game(t_data *data)*/
/*{*/
/*	ft_printf("GAME RESET...\n...\n...\n...\n");*/
/*	free(data->map);*/
/*	load_map(data);*/
/*	get_coins(data);*/
/*	get_positions(data);*/
/*	exit_check(data);*/
/*	data->player->dir = 'd';*/
/*}*/

void	good_game(t_data *data)
{
	annihilate(data, "\n\n\n			!!! YOU WON !!!\n\n\n", 0);
}

void	game_over(t_data *data)
{
	annihilate(data, "\n\n\n			!!! GAME OVER !!!\n\n\n", 0);
}

int	update_game(t_data *data)
{
	data->time++;
	if (data->player->x == data->enemy->x && data->player->y == data->enemy->y)
		game_over(data);
	if (data->time == FRAME_TIME)
	{
		if (data->enemy->is_there)
		{
			scan_for_player(data);
			enemy_logic(data);
			if (data->enemy->move_time < 4)
				data->enemy->move_time++;
			else
				data->enemy->move_time = 0;
		}
		next_frame(data);
		if (data->coins->frame < 4)
			data->coins->frame++;
		else
			data->coins->frame = 1;
		data->time = 0;
	}
	return (FRAME_TIME);
}
