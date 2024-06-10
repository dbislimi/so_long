/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:15:22 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 19:29:03 by dbislimi         ###   ########.fr       */
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
			data->texture[COIN1], x * 32, y * 32);
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
	data->texture = malloc(sizeof(void *) * 24);
	data->texture[FLOOR] = xpm_to_image(data, FLOORXPM);
	data->texture[WALL] = xpm_to_image(data, WALLXPM);
	data->texture[PLAYERR] = xpm_to_image(data, PLAYERRXPM);
	data->texture[COIN1] = xpm_to_image(data, COLLECTIBLE1XPM);
	data->texture[4] = xpm_to_image(data, COLLECTIBLE2XPM);
	data->texture[5] = xpm_to_image(data, COLLECTIBLE3XPM);
	data->texture[6] = xpm_to_image(data, COLLECTIBLE4XPM);
	data->texture[7] = xpm_to_image(data, COLLECTIBLE5XPM);
	data->texture[8] = xpm_to_image(data, COLLECTIBLE6XPM);
	data->texture[9] = xpm_to_image(data, COLLECTIBLE7XPM);
	data->texture[10] = xpm_to_image(data, COLLECTIBLE8XPM);
	data->texture[COIN9] = xpm_to_image(data, COLLECTIBLE9XPM);
	data->texture[EXIT] = xpm_to_image(data, EXITXPM);
	data->texture[PLAYERL] = xpm_to_image(data, PLAYERLXPM);
	data->texture[PLAYERONEXITR] = xpm_to_image(data, ONEXITR);
	data->texture[PLAYERONEXITL] = xpm_to_image(data, ONEXITL);
	data->texture[EXITOPEN1] = xpm_to_image(data, EXITOPEN1XPM);
	data->texture[17] = xpm_to_image(data, EXITOPEN2XPM);
	data->texture[18] = xpm_to_image(data, EXITOPEN3XPM);
	data->texture[19] = xpm_to_image(data, EXITOPEN4XPM);
	data->texture[20] = xpm_to_image(data, EXITOPEN5XPM);
	data->texture[21] = xpm_to_image(data, EXITOPEN6XPM);
	data->texture[EXITOPEN7] = xpm_to_image(data, EXITOPEN7XPM);
	data->texture[23] = NULL;
}
