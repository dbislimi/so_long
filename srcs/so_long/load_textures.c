/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:15:22 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 17:10:54 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_image(t_data *data, int image, int x, int y)
{
	if (image != -1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[image], x * 32, y * 32);
		return ;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->texture[FLOOR], x * 32, y * 32);
	if (data->map_data.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[WALL], x * 32, y * 32);
	else if (data->map_data.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[PLAYERR], x * 32, y * 32);
	else if (data->map_data.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[COINS], x * 32, y * 32);
	else if (data->map_data.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->texture[EXIT], x * 32, y * 32);
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
			put_image(data, -1, j, i);
	}
}

void	*xpm_to_image(t_data *data, char *name)
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
	data->texture = malloc(sizeof(void *) * 9);
	data->texture[FLOOR] = xpm_to_image(data, FLOORXPM);
	data->texture[WALL] = xpm_to_image(data, WALLXPM);
	data->texture[PLAYERR] = xpm_to_image(data, PLAYERRXPM);
	data->texture[COINS] = xpm_to_image(data, COLLECTIBLEXPM);
	data->texture[EXIT] = xpm_to_image(data, EXITXPM);
	data->texture[PLAYERL] = xpm_to_image(data, PLAYERLXPM);
	data->texture[PLAYERONEXITR] = xpm_to_image(data, ONEXITR);
	data->texture[PLAYERONEXITL] = xpm_to_image(data, ONEXITL);
	data->texture[8] = NULL;
}
