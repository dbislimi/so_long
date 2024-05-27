/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:54:50 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/27 16:43:00 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_map_data
{
	char		**map;
	int				fd;
	unsigned int	x;
	unsigned int	y;
}	t_map_data;

void	ft_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	check_filename(char	*file)
{
	int	i;

	i = ft_strlen(file);
	if (ft_strcmp(file + i - 4, ".ber"))
		ft_exit(BAD_EXTENSION);
	return (open(file, O_RDONLY));
}

unsigned int	count_lines(int fd)
{
	int	res;
	char *line;

	res = 0;
	line = get_next_line(fd);
	while (line)
	{
		++res;
		free(line);
		line = get_next_line(fd);
	}
	return (res);
}
void	fill_tab(char **map, char **file, int start)
int	clean_tab(char **file)
{
	char	**map;
	int		size;
	int		i;
	int		j;

	i = -1;
	size = 0;
	while (file[++i])
	{
		j = 0;
		while (file[i][j])
			if (file[i][j++] == '1')
				break ;
	}
	while (file[i][j] == '1')
	{
		if (file[i++][j] != 1)
			break ;
		++size;
	}
	map = malloc(sizeof(char *) * (size + 1));
	fill_tab(map, file, j);
}
void	file_to_tab(t_map_data *map)
{
	unsigned int		i;

	i = 0;
	while (i < map->y)
	{
		map->map[i++] = get_next_line(map->fd);
		// if (ft_strlen(map->map[i]) != map->x)
		// {
		// 	close(map->fd);
		// 	free_tab(map->map);
		// 	ft_exit(INVALID_MAP);
		// }
	}
	map->map[i] = NULL;
	if (!clean_tab(map->map));
		ft_exit(INVALID_MAP);
}

void	map_init(t_map_data *map, char *file)
{
	int	i;
	
	i = 0;
	map->y = count_lines(map->fd);
	if (map->y == 0)
		ft_exit(EMPTY_FILE);
	close(map->fd);
	map->fd = open(file, O_RDONLY);
	map->map = malloc(sizeof(char *) * (map->y + 1));
	if (!map->map)
		return ;
	file_to_tab(map);
	if (!is_valid_map(map))
		ft_exit(INVALID_MAP);
}

int	main(int ac, char **av)
{
	t_map_data	map;
	int		i = 0;

	map.map = NULL;
	if (ac == 1)
		ft_exit(MISSING_FILE);
	map.fd = check_filename(av[1]);
	if (map.fd < 0)
		ft_exit(NOT_FOUND);
	map_init(&map, av[1]);
	close(map.fd);
	if (!map.map)
		return (1);
	while (map.map[i])
		printf("%s", map.map[i++]);
	free_tab(map.map);
	// free(map);
}
