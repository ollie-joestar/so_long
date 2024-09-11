/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:02:44 by oohnivch          #+#    #+#             */
/*   Updated: 2024/08/28 16:14:09 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemy_right(t_data *data)
{
	if (find_char("0Pe", data->map[data->enemy->y][data->enemy->x + 1]))
	{
		data->map[data->enemy->y][data->enemy->x] = '0';
		data->map[data->enemy->y][data->enemy->x + 1] = 'O';
		data->enemy->x += 1;
		data->enemy->dir = 'r';
	}
	else
		data->enemy->dir = 'd';
}

void	move_enemy_left(t_data *data)
{
	if (find_char("0Pe", data->map[data->enemy->y][data->enemy->x - 1]))
	{
		data->map[data->enemy->y][data->enemy->x] = '0';
		data->map[data->enemy->y][data->enemy->x - 1] = 'O';
		data->enemy->x -= 1;
		data->enemy->dir = 'l';
	}
	else
		data->enemy->dir = 'u';
}

void	move_enemy_up(t_data *data)
{
	if (find_char("0Pe", data->map[data->enemy->y - 1][data->enemy->x]))
	{
		data->map[data->enemy->y][data->enemy->x] = '0';
		data->map[data->enemy->y - 1][data->enemy->x] = 'O';
		data->enemy->y -= 1;
		data->enemy->dir = 'u';
	}
	else
		data->enemy->dir = 'r';
}

void	move_enemy_down(t_data *data)
{
	if (find_char("0Pe", data->map[data->enemy->y + 1][data->enemy->x]))
	{
		data->map[data->enemy->y][data->enemy->x] = '0';
		data->map[data->enemy->y + 1][data->enemy->x] = 'O';
		data->enemy->y += 1;
		data->enemy->dir = 'd';
	}
	else
		data->enemy->dir = 'l';
}
