/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:22:46 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 16:48:16 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	change_texture(int texture, char *new_texure, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->texture[texture]);
	data->texture[texture] = xpm_to_image(data, new_texure);
}
