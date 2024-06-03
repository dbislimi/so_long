/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:35:09 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/03 19:03:14 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_data *data)
{
	ft_free(data, NULL);
	return (0);
}

void	update_position(t_data *data, t_coo current, t_coo new, int *flag)
{
	if (*flag == 2)
	{
		data->map_data.map[current.y][current.x] = 'E';
		*flag = 0;
	}
	else
		data->map_data.map[current.y][current.x] = '0';
	if (*flag == 1)
		++*flag;
	data->map_data.map[new.y][new.x] = 'P';
}

void	move(int direction, t_data *data, t_coo P)
{
	t_coo		dest;
	static int	exit_flag;
	static int	moves;

	dest = P;
	++moves;
	if (direction == UP)
		--dest.y;
	else if (direction == DOWN)
		++dest.y;
	else if (direction == LEFT)
		--dest.x;
	else
		++dest.x;
	if (data->map_data.map[dest.y][dest.x] == 'C')
		--data->map_data.collectables;
	else if (data->map_data.collectables == 0
		&& data->map_data.map[dest.y][dest.x] == 'E')
		ft_free(data, NULL);
	else if (data->map_data.collectables != 0
		&& data->map_data.map[dest.y][dest.x] == 'E')
		exit_flag = 1;
	update_position(data, P, dest, &exit_flag);
	rendering(data);
	ft_printf("Number of moves : %d\n", moves);
}

int	on_keypress(int keysym, t_data *data)
{
	t_coo	player;

	player = search_char('P', data->map_data.map);
	if (keysym == UP
		&& data->map_data.map[player.y - 1][player.x] != '1')
		move(UP, data, player);
	else if (keysym == DOWN
		&& data->map_data.map[player.y + 1][player.x] != '1')
		move(DOWN, data, player);
	else if (keysym == LEFT
		&& data->map_data.map[player.y][player.x - 1] != '1')
		move(LEFT, data, player);
	else if (keysym == RIGHT
		&& data->map_data.map[player.y][player.x + 1] != '1')
		move(RIGHT, data, player);
	else if (keysym == ESC)
		ft_free(data, NULL);
	return (0);
}
