/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:51:28 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/29 14:56:21 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**get_map(char **file, int y, int size)
{
	char 	**map;
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
			break;
	}
	while (file[i++] && file[i - 1][j] == '1')
		++size;
	file = get_map(file, i - size - 1, size);
	return (file);
}

static char	**file_to_tab(char *file)
{
	char	**map;
	size_t	nb_of_lines;
	size_t	i;
	int		fd;
	
	i = 0;
	fd = check_filename(file);
	if (fd < 0)
		ft_exit(NOT_FOUND);
	nb_of_lines = count_lines(fd);
	if (nb_of_lines == 0)
		ft_exit(EMPTY_FILE);
	close(fd);
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (nb_of_lines + 1));
	if (!map)
		return (NULL);
	while (i < nb_of_lines)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	print_tab(map);
	map = clean_tab(map);
	close(fd);
	return (map);
}

char	**map_init(char *file)
{
	char	**map;
	int		i;
	
	i = 0;
	map = file_to_tab(file);
	if (map == NULL)
		return (NULL);
	// if (!check_validity(map))
	// {
	// 	free_tab(map);
	// 	ft_exit(INVALID_MAP);
	// }
	return (map);
}
