/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:51:28 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/28 19:13:26 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	file_to_tab(char **map, int fd, int nb_of_lines)
{
	unsigned int		i;

	i = 0;
	while (i < nb_of_lines)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	map = clean_tab(map);
	close(fd);
}

void	map_init(char **map, char *file)
{
	int	fd;
	int	nb_of_lines;
	int	i;
	
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
		return ;
	file_to_tab(map, fd, nb_of_lines);
	if (!check_validity(map))
	{
		free_tab(map);
		ft_exit(INVALID_MAP);
	}
}
