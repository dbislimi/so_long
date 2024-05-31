/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:02:30 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/31 20:17:14 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_data *data, char *msg)
{
	if (data->map_data.map)
		free_tab(data->map_data.map);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);	
		free(data->mlx_ptr);
	}
	if (data->texture)
		free_tab((char **)data->texture);
	ft_exit(msg);
}
