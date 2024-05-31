/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:59:27 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/30 18:58:25 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdupforsl(const char *s)
{
	char	*dup;
	size_t	j;
	size_t	i;
	size_t	len;

	i = 0;
	j = 0;
	len = 1;
	while (s[i] && ft_strchr("01CEP", s[i]) == NULL)
		++i;
	while (s[i + len] && ft_strchr("01CEP", s[i + len]))
		++len;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (len--)
		dup[j++] = s[i++];
	dup[j] = '\0';
	return (dup);
}

int	check_filename(char	*file)
{
	int	i;

	i = ft_strlen(file);
	if (ft_strcmp(file + i - 4, ".ber"))
		return (-1);
	return (open(file, O_RDONLY));
}

int	is_rectangle(char **map)
{
	size_t	ref;
	size_t	i;

	i = 0;
	ref = ft_strlen(map[0]);
	while (map[++i])
		if (ft_strlen(map[i]) != ref)
			return (0);
	return (1);
}

int	is_closed(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		if (i == 0 || map[i + 1] == NULL)
		{
			j = 0;
			while (map[i][j])
				if (map[i][j++] != '1')
					return (0);
		}
		else if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
		++i;
	}
	return (1);
}

int	check_for_path(char **map)
{
	t_coordinates	co;
	char			**dup;

	co = search_char('P', map);
	dup = map_dup(map);
	flood_fill(co.y, co.x, dup);
	if (count_char('C', dup) != 0 || count_char('E', dup) != 0)
	{
		free_tab(dup);
		return (0);
	}
	free_tab(dup);
	return (1);
}
