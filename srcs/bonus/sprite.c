/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:44:37 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 19:45:03 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_coins(t_data *data, int image)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j])
		{
			if (data->map_data.map[i][j] == 'C')
				put_image(data, image, j, i);
		}
	}
}

int	sprite(t_data *data)
{
	static int	i;
	static int	j;

	usleep(90000);
	if (j == 0 || j == COIN9)
		j = COIN1;
	update_coins(data, j);
	++j;
	if (data->map_data.collectibles != 0)
		return (0);
	if (i == 0 || i == EXITOPEN7)
		i = EXITOPEN1;
	put_image(data, i, data->map_data.exit.x, data->map_data.exit.y);
	++i;
	return (1);
}
