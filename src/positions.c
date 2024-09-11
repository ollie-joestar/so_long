/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:33:42 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 10:52:13 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_player_position(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->biome->start = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player->x = x;
				data->player->y = y;
				data->biome->start++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (data->biome->start != 1)
		annihilate(data, "Error\nWrong number of start locations!\n", 1);
}

static void	get_exit_position(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->biome->exit = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				data->biome->x = x;
				data->biome->y = y;
				data->biome->exit++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (data->biome->exit != 1)
		annihilate(data, "Error\nWrong number of exit locations!\n", 1);
}

static void	get_enemy_position(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->enemy->is_there = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'O')
			{
				data->enemy->x = x;
				data->enemy->y = y;
				data->enemy->is_there++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (data->enemy->is_there > 1)
		annihilate(data, "Error\nToo many enemies\n", 1);
	return ;
}

void	get_coins(t_data *data)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	if (i < 1)
		annihilate(data, "Error\nNot enough ram sticks on the map!\n", 1);
	data->coins->coinnum = i;
	data->coins->coincheck = i;
}

void	get_positions(t_data *data)
{
	get_player_position(data);
	get_exit_position(data);
	get_enemy_position(data);
}
