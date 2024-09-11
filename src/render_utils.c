/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:53:08 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 10:52:21 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*image_check(t_data *data, char c)
{
	if (c == '1')
		return (data->biome->wall);
	if (c == '0')
		return (data->biome->floor);
	if (c == 'C')
		return (get_coin_img(data));
	if (c == 'E')
		return (data->biome->exit_closed);
	if (c == 'e')
		return (get_closed_exit_img(data));
	if (c == 'F')
		return (data->biome->exit_open);
	if (c == 'P')
		return (get_player_img(data));
	if (c == 'O')
		return (get_enemy_img(data));
	return (NULL);
}

void	next_frame(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y] && data->map[y][x])
		{
			img = image_check(data, data->map[y][x]);
			y *= 32;
			x *= 32;
			if (img)
				mlx_put_image_to_window(data->mlx, data->win, img, x, y);
			x = (x / 32) + 1;
			y /= 32;
		}
		x = 0;
		y++;
	}
	mlx_string_put(data->mlx, data->win, 4, 12, 0, "Moves made: ");
	mlx_string_put(data->mlx, data->win, 84, 12, 0, data->biome->cmove);
}
