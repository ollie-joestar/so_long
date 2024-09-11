/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:03:33 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 15:41:29 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	initiate(t_data *data)
{
	char	*cmove;

	init_player(data);
	init_biome(data);
	init_coins(data);
	init_enemy(data);
	cmove = ft_itoa(data->biome->move);
	if (!cmove)
		annihilate(data, "Error\n", 1);
	data->biome->cmove = cmove;
	get_positions(data);
	get_coins(data);
	if (!validate_map(data))
		annihilate(data, "Error\nInvalid map!\n", 1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data || argc != 2)
		return (annihilate(data, "Error\n", 1), 1);
	data->argv = argv;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (annihilate(data, "Error\n", 1), 1);
	mlx_get_screen_size(data->mlx, &data->screen_x, &data->screen_y);
	if (!data->screen_x || !data->screen_y)
		return (annihilate(data, "Error\n", 1), 1);
	load_map(data);
	data->win = mlx_new_window(data->mlx,
			data->win_width, data->win_height, "so_long");
	if (!data->win)
		return (annihilate(data, "Error\n", 1), 1);
	initiate(data);
	next_frame(data);
	mlx_loop_hook(data->mlx, update_game, data);
	mlx_key_hook(data->win, &key_hook, data);
	mlx_hook(data->win, 17, 0, &button_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
