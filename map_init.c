/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:51:28 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/30 19:00:52 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**get_map(char **file, int y, int size)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	while (i < size)
		map[i++] = ft_strdupforsl(file[y++]);
	map[i] = NULL;
	free_tab(file);
	return (map);
}

static char	**clean_tab(char **file)
{
	int		size;
	int		i;
	int		j;

	i = -1;
	size = 0;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
			if (file[i][j] == '1')
				break ;
		if (file[i][j] == '1')
			break ;
	}
	while (file[i++] && file[i - 1][j] == '1')
		++size;
	file = get_map(file, i - size - 1, size);
	return (file);
}

static char	**file_to_tab(char *file, size_t nb_of_lines)
{
	char	**map;
	size_t	i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (nb_of_lines + 1));
	if (!map)
		return (NULL);
	while (i <= nb_of_lines)
		map[i++] = get_next_line(fd);
	close(fd);
	map = clean_tab(map);
	return (map);
}

static int	check_validity(char **map)
{
	if (count_char('E', map) != 1 || count_char('C', map) < 1
		|| count_char('P', map) != 1)
		return (0);
	if (!is_rectangle(map))
		return (0);
	if (!is_closed(map))
		return (0);
	if (!check_for_path(map))
		return (0);
	return (1);
}

void	map_init(char *file, t_data *data)
{
	size_t	nb_of_lines;
	int				i;
	int				fd;
	
	i = 0;
	fd = check_filename(file);
	if (fd < 0)
		ft_free(data, NOT_FOUND);
	nb_of_lines = count_lines(fd);
	close(fd);
	if (nb_of_lines == 0)
		ft_free(data, EMPTY_FILE);
	data->map_data->map = file_to_tab(file, nb_of_lines);
	if (data->map_data->map == NULL)
		return ;
	if (!check_validity(data->map_data->map))
		ft_free(data, INVALID_MAP);
}
