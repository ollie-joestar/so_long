/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:05:48 by oohnivch          #+#    #+#             */
/*   Updated: 2024/09/11 14:20:22 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static size_t	file_line_num(t_data *data)
{
	size_t	line_num;
	char	*temp;
	int		fd;

	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
		annihilate (data, "Error\nFailed to open map!\n", 1);
	line_num = 0;
	temp = get_next_line(fd, &data->errno);
	while (temp)
	{
		line_num++;
		if (data->errno == -1)
			annihilate (data, "Error\nFailed to get next line!\n", 1);
		free(temp);
		temp = get_next_line(fd, &data->errno);
	}
	if (-1 == close(fd))
		annihilate (data, "Error\nFailed to close map!\n", 1);
	if (data->errno == -1)
		annihilate (data, "Error\nFailed to get next line!\n", 1);
	return (line_num);
}

static void	ft_parsemap(t_data *data)
{
	int		fd;
	int		x;
	int		line_num;
	char	*line;
	char	**map;

	line_num = file_line_num(data);
	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
		annihilate (data, "Error\nFailed to open map!\n", 1);
	map = (char **)ft_calloc(sizeof(char *), line_num + 1);
	data->map = map;
	if (map == NULL)
		annihilate (data, "Error\nFailed to alloc map!\n", 1);
	x = 0;
	line = get_next_line(fd, &data->errno);
	while (line)
	{
		map[x++] = line;
		line = get_next_line(fd, &data->errno);
	}
	if (-1 == close(fd))
		annihilate (data, "Error\nFailed to close map!\n", 1);
	if (!(data->map) || !(data->map[0]) || data->errno == -1)
		annihilate(data, "Error\nFailed to parse the map gnl\n", 1);
}

void	load_map(t_data *data)
{
	check_extension(data);
	ft_parsemap(data);
	data->win_width = ft_linelen(data->map[0]) - 1;
	data->win_height = ft_arrlen(data->map);
	if (data->win_width > data->screen_x / 32 || \
		data->win_height >= data->screen_y)
		annihilate(data, "Error\nWrong map size!\n", 1);
	data->win_width *= 32;
	data->win_height *= 32;
	if (data->win_height >= data->screen_y || data->win_height <= 0 || \
		data->win_width >= data->screen_x || data->win_width <= 0)
		annihilate(data, "Error\nWrong map size!\n", 1);
}

static void	check_forbidden_chars(t_data *data)
{
	size_t	row;
	size_t	column;

	row = 0;
	column = 0;
	while (data->map[row])
	{
		while (data->map[row][column])
		{
			if (!ft_strchr("10EPCO\n", data->map[row][column]))
				annihilate(data, "Error\nForbidden char in map\n", 1);
			column++;
		}
		row++;
		column = 0;
	}
}

int	validate_map(t_data *data)
{
	int	vertical_result;
	int	horizontal_result;

	check_forbidden_chars(data);
	horizontal_result = horizontal_wall_check(data);
	if (horizontal_result == 0)
		annihilate(data, "Error\nMap is not closed off horizontally!\n", 1);
	vertical_result = vertical_wall_check(data);
	if (vertical_result == 0)
		annihilate(data, "Error\nMap is not closed off vertically!\n", 1);
	rectangle_check(data);
	if (!(find_path(data, data->player->y, data->player->x)))
		annihilate(data, "Error\nNo valid path!\n", 1);
	ft_freecarr(data->map);
	load_map(data);
	return (1);
}
