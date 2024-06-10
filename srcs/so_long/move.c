/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:17:23 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 16:48:23 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_up(t_coo player, t_coo *dest, char **map)
{
	if (map[player.y - 1][player.x] != '1')
		--(*dest).y;
}

static void	move_down(t_coo player, t_coo *dest, char **map)
{
	if (map[player.y + 1][player.x] != '1')
		++(*dest).y;
}

static void	move_right(t_coo player, t_coo *dest, char **map)
{
	if (map[player.y][player.x + 1] != '1')
		++(*dest).x;
}

static void	move_left(t_coo player, t_coo *dest, char **map)
{
	if (map[player.y][player.x - 1] != '1')
		--(*dest).x;
}

void	move(int direction, t_data *data)
{
	t_coo		dest;
	static int	moves;

	dest = data->map_data.player;
	if (direction == UP)
		move_up(data->map_data.player, &dest, data->map_data.map);
	else if (direction == DOWN)
		move_down(data->map_data.player, &dest, data->map_data.map);
	else if (direction == LEFT)
		move_left(data->map_data.player, &dest, data->map_data.map);
	else
		move_right(data->map_data.player, &dest, data->map_data.map);
	if (dest.y == data->map_data.player.y && dest.x == data->map_data.player.x)
		return ;
	update_position(direction, data->map_data.player, dest, data);
	data->map_data.player = dest;
	ft_printf("Number of moves : %d\n", ++moves);
}
