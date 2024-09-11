/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:18:24 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 14:02:16 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	*get_enemy_img(t_data *data)
{
	if (data->enemy->dir == 'u')
		return (data->enemy->enemy_u);
	if (data->enemy->dir == 'd')
		return (data->enemy->enemy_d);
	if (data->enemy->dir == 'l')
		return (data->enemy->enemy_l);
	if (data->enemy->dir == 'r')
		return (data->enemy->enemy_r);
	return (NULL);
}

void	*get_player_img(t_data *data)
{
	if (data->player->dir == 'u')
		return (data->player->player_u);
	if (data->player->dir == 'd')
		return (data->player->player_d);
	if (data->player->dir == 'l')
		return (data->player->player_l);
	if (data->player->dir == 'r')
		return (data->player->player_r);
	return (NULL);
}

void	*get_closed_exit_img(t_data *data)
{
	if (data->player->dir == 'u')
		return (data->player->player_eu);
	if (data->player->dir == 'd')
		return (data->player->player_ed);
	if (data->player->dir == 'l')
		return (data->player->player_el);
	if (data->player->dir == 'r')
		return (data->player->player_er);
	return (NULL);
}

void	*get_coin_img(t_data *data)
{
	if (data->coins->frame == 1)
		return (data->coins->coin_1);
	if (data->coins->frame == 2)
		return (data->coins->coin_2);
	if (data->coins->frame == 3)
		return (data->coins->coin_3);
	if (data->coins->frame == 4)
		return (data->coins->coin_4);
	return (NULL);
}
