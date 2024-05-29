/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:54:50 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/29 14:45:38 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	map = NULL;
	if (ac == 1)
		ft_exit(MISSING_FILE);
	map = map_init(av[1]);
	if (!map)
		return (1);
	print_tab(map);
	free_tab(map);
}
