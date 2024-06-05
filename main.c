/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:54:50 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/05 19:26:48 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	data_init(t_data *data, char *filename)
{
	data->map_data.map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->texture = NULL;
	map_init(filename, data);
	if (data->map_data.map == NULL)
		ft_free(data, MALLOC);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_free(data, MALLOC);
	data->map_data.length = -1;
	data->map_data.width = -1;
	while (data->map_data.map[0][++data->map_data.length])
		;
	while (data->map_data.map[++data->map_data.width])
		;
	load_textures(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map_data.length * 64,
			data->map_data.width * 64, "so_long");
	if (!data->win_ptr)
		ft_free(data, MALLOC);
	rendering(data);
}

void	free_voidtab(void **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		ft_exit(MISSING_FILE);
	data_init(&data, av[1]);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &data);
	mlx_loop(data.mlx_ptr);
	ft_free(&data, NULL);
	return (0);
}
