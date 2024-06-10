/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:41:56 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 16:48:27 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

size_t	count_lines(int fd)
{
	size_t	res;
	char	*line;

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
