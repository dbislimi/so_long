/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:55:12 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/28 19:13:54 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../mlx/mlx.h"

# define BAD_EXTENSION "Error\nInvalid extension\n"
# define MISSING_FILE "Error\nMissing file\n"
# define INVALID_MAP "Error\nInvalid map\n"
# define EMPTY_FILE "Error\nEmpty file (or not a file)\n"
# define NOT_FOUND "Error\nFile not found\n"


void	map_init(char **map, char *file);
char	**clean_tab(char **file);

#endif