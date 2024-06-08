/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:22:46 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/08 18:09:11 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_texture(int texture, char *new_texure, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->texture[texture]);
	data->texture[texture] = xpm_to_image(data, new_texure);
}

void	check_texture(int direction, t_coo dest, t_data *data)
{
	static int	prev;

	if (prev == 0)
		prev = RIGHT;
	if (data->map_data.map[dest.y][dest.x] == 'E' && prev == RIGHT)
		change_texture(PLAYER, ONEXITR, data);
	else if (data->map_data.map[dest.y][dest.x] == 'E' && prev == LEFT)
		change_texture(PLAYER, ONEXITL, data);
	else if (data->map_data.map[dest.y][dest.x] != 'E' && prev == LEFT)
		change_texture(PLAYER, PLAYERLxpm, data);
	else if (data->map_data.map[dest.y][dest.x] != 'E' && prev == RIGHT)
		change_texture(PLAYER, PLAYERRxpm, data);
	prev = direction;
}