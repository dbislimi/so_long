/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:35:09 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 16:47:54 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	destroy(t_data *data)
{
	ft_free(data, NULL);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == UP || keysym == DOWN || keysym == LEFT || keysym == RIGHT)
		move(keysym, data);
	else if (keysym == ESC)
		ft_free(data, NULL);
	return (0);
}
