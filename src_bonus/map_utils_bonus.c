/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:39:15 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 14:02:16 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	check_extension(t_data *data)
{
	size_t	i;
	size_t	len;
	size_t	offset;
	char	*ber;

	ber = ".ber";
	len = ft_strlen(data->argv[1]);
	if (len < 5)
		annihilate(data, "Error\nWrong map extension length\n", 1);
	offset = len - 5;
	i = -1;
	if (data->argv[1][offset++] == '/')
		annihilate(data, "Error\nWrong map extension slash\n", 1);
	while (ber[++i])
	{
		if (ber[i] != data->argv[1][offset + i])
			annihilate(data, "Error\nWrong map extension ending\n", 1);
	}
}

int	find_path(t_data *data, int y, int x)
{
	if (y <= 0 || y >= data->win_height / 32 || \
		x <= 0 || x >= data->win_width / 32 || \
		data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'C')
		data->coins->coinnum--;
	if (data->map[y][x] == 'E')
		data->biome->exit--;
	data->map[y][x] = '1';
	find_path(data, y - 1, x);
	find_path(data, y + 1, x);
	find_path(data, y, x + 1);
	find_path(data, y, x - 1);
	if (data->coins->coinnum == 0 && data->biome->exit == 0)
		return (1);
	else
		return (0);
}

void	rectangle_check(t_data *data)
{
	int		y;
	size_t	len;

	y = 0;
	if (data->map && data->map[y])
		len = ft_linelen_sl(data->map[y]);
	while (data->map[y])
	{
		if (len == ft_linelen_sl(data->map[y]))
			y++;
		else
			annihilate(data, "Error\nMap is not rectangular!\n", 1);
	}
}

int	vertical_wall_check(t_data *data)
{
	size_t	y;
	size_t	x;
	size_t	arrlen;
	size_t	linelen;

	y = 0;
	x = 0;
	arrlen = ft_arrlen(data->map);
	linelen = ft_linelen(data->map[0]);
	while (data->map[y])
	{
		if (data->map[y][x] != '1' && data->map[y][x] != 0)
			return (0);
		y++;
	}
	x = -2 + linelen;
	y = 0;
	while (data->map[y])
	{
		if (data->map[y][x] != '1')
			return (0);
		y++;
	}
	return ((y == arrlen) && (x == -2 + linelen));
}

int	horizontal_wall_check(t_data *data)
{
	size_t	y;
	size_t	x;
	size_t	arrlen;
	size_t	linelen;

	y = 0;
	x = 0;
	arrlen = ft_arrlen(data->map);
	linelen = ft_linelen(data->map[0]);
	while (data->map[y][x] && data->map[y][x] != '\n')
	{
		if (data->map[y][x] != '1')
			return (0);
		x++;
	}
	y = -1 + arrlen;
	x = 0;
	while (data->map[y][x] && data->map[y][x] != '\n')
	{
		if (data->map[y][x] != '1')
			return (0);
		x++;
	}
	return ((y == -1 + arrlen) && (x == -1 + linelen));
}
