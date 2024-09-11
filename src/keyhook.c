/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:45:19 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 14:27:00 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_right(t_data *data)
{
	if (data->map[data->player->y][data->player->x + 1] != '1')
	{
		if (data->map[data->player->y][data->player->x + 1] == 'C')
			data->coins->coincheck -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->map[data->player->y][data->player->x + 1] = 'P';
		data->player->x += 1;
	}
	data->player->dir = 'r';
	data->biome->move++;
	free(data->biome->cmove);
	data->biome->cmove = ft_itoa(data->biome->move);
	ft_printf("Moves made: %d\n", data->biome->move);
}

static void	move_left(t_data *data)
{
	if (data->map[data->player->y][data->player->x - 1] != '1')
	{
		if (data->map[data->player->y][data->player->x - 1] == 'C')
			data->coins->coincheck -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->map[data->player->y][data->player->x - 1] = 'P';
		data->player->x -= 1;
	}
	data->player->dir = 'l';
	data->biome->move++;
	free(data->biome->cmove);
	data->biome->cmove = ft_itoa(data->biome->move);
	ft_printf("Moves made: %d\n", data->biome->move);
}

static void	move_up(t_data *data)
{
	if (data->map[data->player->y - 1][data->player->x] != '1')
	{
		if (data->map[data->player->y - 1][data->player->x] == 'C')
			data->coins->coincheck -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->map[data->player->y - 1][data->player->x] = 'P';
		data->player->y -= 1;
	}
	data->player->dir = 'u';
	data->biome->move++;
	free(data->biome->cmove);
	data->biome->cmove = ft_itoa(data->biome->move);
	ft_printf("Moves made: %d\n", data->biome->move);
}

static void	move_down(t_data *data)
{
	if (data->map[data->player->y + 1][data->player->x] != '1')
	{
		if (data->map[data->player->y + 1][data->player->x] == 'C')
			data->coins->coincheck -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->map[data->player->y + 1][data->player->x] = 'P';
		data->player->y += 1;
	}
	data->player->dir = 'd';
	data->biome->move++;
	free(data->biome->cmove);
	data->biome->cmove = ft_itoa(data->biome->move);
	ft_printf("Moves made: %d\n", data->biome->move);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == RIGHT || keycode == 100 || keycode == 108)
		move_right(data);
	if (keycode == UP || keycode == 119 || keycode == 107)
		move_up(data);
	if (keycode == DOWN || keycode == 115 || keycode == 106)
		move_down(data);
	if (keycode == LEFT || keycode == 97 || keycode == 104)
		move_left(data);
	if (keycode == 65307)
		annihilate(data, "Exit Game\n", 1);
	exit_check(data);
	mlx_clear_window(data->mlx, data->win);
	next_frame(data);
	return (0);
}
