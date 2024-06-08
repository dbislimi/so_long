/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:17:23 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/08 17:29:12 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_coo player, t_coo *dest, t_data *data)
{
	if (data->map_data.map[player.y - 1][player.x] != '1')
		--(*dest).y;
}

static void	move_down(t_coo player, t_coo *dest, t_data *data)
{
	if (data->map_data.map[player.y + 1][player.x] != '1')
		++(*dest).y;
}

static void	move_right(t_coo player, t_coo *dest, t_data *data)
{
	if (data->map_data.map[player.y][player.x + 1] != '1')
		++(*dest).x;
}

static void	move_left(t_coo player, t_coo *dest, t_data *data)
{
	if (data->map_data.map[player.y][player.x - 1] != '1')
		--(*dest).x;
}

void	move(int direction, t_data *data)
{
	t_coo		player;
	t_coo		dest;
	static int	moves;
	
	player = search_char('P', data->map_data.map);
	dest = player;
	if (direction == UP)
		move_up(player, &dest, data);
	else if (direction == DOWN)
		move_down(player, &dest, data);
	else if (direction == LEFT)
		move_left(player, &dest, data);
	else
		move_right(player, &dest, data);
	if (data->map_data.map[dest.y][dest.x]
		== data->map_data.map[player.y][player.x])
		return ;
	printf("%d %d\n", data->map_data.exit.x, data->map_data.exit.y);
	check_texture(direction, dest, data);
	update_position(data->map_data.exit, player, dest, data);
	rendering(data);	
	ft_printf("Number of moves : %d\n", ++moves);
}
