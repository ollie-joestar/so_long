/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_logic_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:48:55 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 14:02:15 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	chase_on_x(t_data *data)
{
	if (data->enemy->move_time <= 4)
		data->enemy->move_time++;
	else
		data->enemy->move_time = 0;
	if (data->player->y > data->enemy->y)
		data->enemy->dir = 'd';
	else
		data->enemy->dir = 'u';
}

void	chase_on_y(t_data *data)
{
	if (data->enemy->move_time <= 4)
		data->enemy->move_time++;
	else
		data->enemy->move_time = 0;
	if (data->player->x > data->enemy->x)
		data->enemy->dir = 'r';
	else
		data->enemy->dir = 'l';
}

void	scan_for_player(t_data *data)
{
	if (data->player->x == data->enemy->x)
		chase_on_x(data);
	else if (data->player->y == data->enemy->y)
		chase_on_y(data);
}

void	enemy_logic(t_data *data)
{
	if (data->enemy->move_time >= 4)
	{
		if (data->enemy->dir == 'u')
			move_enemy_up(data);
		else if (data->enemy->dir == 'r')
			move_enemy_right(data);
		else if (data->enemy->dir == 'd')
			move_enemy_down(data);
		else if (data->enemy->dir == 'l')
			move_enemy_left(data);
	}
}
