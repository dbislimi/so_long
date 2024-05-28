/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:54:50 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/28 19:14:10 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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
void	printtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
}

int	check_filename(char	*file)
{
	int	i;

	i = ft_strlen(file);
	if (ft_strcmp(file + i - 4, ".ber"))
		ft_exit(BAD_EXTENSION);
	return (open(file, O_RDONLY));
}






int	main(int ac, char **av)
{
	char	**map;

	map = NULL;
	if (ac == 1)
		ft_exit(MISSING_FILE);
	map_init(map, av[1]);
	if (!map)
		return (1);
	printtab(map);
	free_tab(map);
}
