/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:15:22 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/31 20:49:23 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->texture[0], x * 32, y * 32);
	if (data->map_data.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->texture[1], x * 32, y * 32);
	if (data->map_data.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->texture[2], x * 32, y * 32);
}

void	rendering(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j])
			put_image(data, j, i);
	}
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
	data->texture = malloc(sizeof(void *) * 4);
	data->texture[0] = xpm_to_image(data, FLOOR);
	data->texture[1] = xpm_to_image(data, WALL);
	data->texture[2] = xpm_to_image(data, PLAYER);
	data->texture[3] = NULL;
	// data.texture[2] = get_image(data, GROUND);
	// data.texture[3] = get_image(data, GROUND);
	// data.texture[4] = get_image(data, GROUND);
}
