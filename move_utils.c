/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:44:40 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/08 18:05:17 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(t_coo exit, t_coo current, t_coo new, t_data *data)
{
	if (data->map_data.map[new.y][new.x] == 'E' && data->map_data.collectables == 0)
		ft_free(data, NULL);
	if (data->map_data.map[exit.y][exit.x] == data->map_data.map[current.y][current.x])
		data->map_data.map[current.y][current.x] = 'E';
	else
		data->map_data.map[current.y][current.x] = '0';
	if (data->map_data.map[new.y][new.x] == 'C')
		--data->map_data.collectables;
	data->map_data.map[new.y][new.x] = 'P';
//	print_tab(data->map_data.map);
}
