/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:53:22 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/28 19:01:05 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strdupforsl(const char *s)
{
	char	*dup;
	size_t	j;
	size_t	i;
	size_t	len;

	i = 0;
	j = 0;
	len = 1;
	while (ft_strchr("01CEP", s[i]) == NULL)
		++i;
	while (ft_strchr("01CEP", s[i + len]))
		++len;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (len--)
		dup[j++] = s[i++];
	dup[j] = '\0';
	return (dup);
}

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

char	**clean_tab(char **file)
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
	while (file[i] && file[i++][j] == '1')
		++size;
	file = get_map(file, i - size - 1, size);
	return (file);
}
