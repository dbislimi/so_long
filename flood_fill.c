/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:34 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/30 15:44:15 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(int i, int j, char **map)
{
	int	n;
	int	m;

	n = -1;
	while (map[++n])
		;
	m = ft_strlen(map[0]);
	if (i < 0 || i >= n || j < 0 || j >= m || ft_strchr("1F", map[i][j]))
		return ;
	else
	{
		map[i][j] = 'F';
		flood_fill(i + 1, j, map);
		flood_fill(i - 1, j, map);
		flood_fill(i, j + 1, map);
		flood_fill(i, j - 1, map);
	}
}
