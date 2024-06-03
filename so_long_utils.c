/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:53:22 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/03 17:06:39 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *msg)
{
	if (!msg)
		exit(EXIT_SUCCESS);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		ft_printf("(null)\n");
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
	ft_printf("\n");
}

char	**map_dup(char **map)
{
	char	**dup;
	int		i;

	i = -1;
	dup = NULL;
	while (map[++i])
		;
	dup = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (map[++i])
		dup[i] = ft_strdup(map[i]);
	dup[i] = NULL;
	return (dup);
}

t_coo	search_char(char c, char **tab)
{
	t_coo	co;

	co.y = -1;
	while (tab[++co.y])
	{
		co.x = -1;
		while (tab[co.y][++co.x])
			if (tab[co.y][co.x] == c)
				return (co);
	}
	co.y = -1;
	co.x = -1;
	return (co);
}

int	count_char(char c, char **tab)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			if (tab[i][j] == c)
				++res;
	}
	return (res);
}
