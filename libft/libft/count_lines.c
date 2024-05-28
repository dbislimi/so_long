/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:55:27 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/28 18:59:30 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
