/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:15:22 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/05 19:26:37 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->texture[FLOOR], x * 64, y * 64);
	if (data->map_data.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[WALL], x * 64, y * 64);
	else if (data->map_data.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[PLAYER], x * 64, y * 64);
	else if (data->map_data.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[COINS], x * 64, y * 64);
	else if (data->map_data.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[4], x * 64, y * 64);
}

void	rendering(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	if (data->map_data.save == NULL)
	{
		while (data->map_data.map[++i])
		{
			j = -1;
			while (data->map_data.map[i][++j])
				put_image(data, j, i);
		}
	}
	else
	{
		while (data->map_data.map[++i])
		{
			j = -1;
			while (data->map_data.map[i][++j])
				if (data->map_data.map[i][j] != data->map_data.save[i][j])
					put_image(data, j, i);
		}
		free_tab(data->map_data.save);
	}
	data->map_data.save = map_dup(data->map_data.map);
}

static void	*xpm_to_image(t_data *data, char *name)
{
	void	*img_ptr;
	int		size;

	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, name,
			&size, &size);
	if (!img_ptr)
		ft_free(data, ASSETS);
	return (img_ptr);
}

void	load_textures(t_data *data)
{
	data->texture = malloc(sizeof(void *) * 6);
	data->texture[FLOOR] = xpm_to_image(data, FLOORxpm);
	data->texture[WALL] = xpm_to_image(data, WALLxpm);
	data->texture[PLAYER] = xpm_to_image(data, PLAYERxpm);
	data->texture[COINS] = xpm_to_image(data, COLLECTABLESxpm);
	data->texture[EXIT] = xpm_to_image(data, EXITxpm);
	data->texture[5] = NULL;
}
