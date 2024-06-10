/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:44:40 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 20:27:29 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	handle_player_texture(int direction, t_coo next, char **map)
{
	static int	prev;

	if (prev == 0)
		prev = RIGHT;
	if (direction == LEFT || direction == RIGHT)
		prev = direction;
	if (map[next.y][next.x] == 'E' && prev == RIGHT)
		return (PLAYERONEXITR);
	if (map[next.y][next.x] == 'E' && prev == LEFT)
		return (PLAYERONEXITL);
	if (prev == RIGHT)
		return (PLAYERR);
	return (PLAYERL);
}

void	update_position(int direction, t_coo player, t_coo next, t_data *data)
{
	int	player_texture;

	if (data->map_data.map[next.y][next.x] == 'E'
		&& data->map_data.collectibles == 0)
		ft_free(data, NULL);
	if (data->map_data.map[next.y][next.x] == 'C')
	{
		--data->map_data.collectibles;
		data->map_data.map[next.y][next.x] = '0';
	}
	if (data->map_data.map[player.y][player.x] == 'E')
		put_image(data, EXIT, player.x, player.y);
	else
	{
		if (data->map_data.collectibles != 0)
			put_image(data, EXIT, data->map_data.exit.x, data->map_data.exit.y);
		put_image(data, FLOOR, player.x, player.y);
	}
	player_texture = handle_player_texture(direction, next, data->map_data.map);
	put_image(data, player_texture, next.x, next.y);
}
