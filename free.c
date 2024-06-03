/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:02:30 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/03 16:27:21 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_texture(void **tab, t_data *data)
{
	size_t	i;

	i = 0;
	while (tab[i])
		mlx_destroy_image(data->mlx_ptr, tab[i++]);
	free(tab);
}

void	ft_free(t_data *data, char *msg)
{
	if (data->map_data.map)
		free_tab(data->map_data.map);
	if (data->texture)
		free_texture(data->texture, data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	ft_exit(msg);
}
