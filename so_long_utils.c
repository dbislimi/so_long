/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:53:22 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/29 13:23:00 by dbislimi         ###   ########.fr       */
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
int	check_filename(char	*file)
{
	int	i;

	i = ft_strlen(file);
	if (ft_strcmp(file + i - 4, ".ber"))
		ft_exit(BAD_EXTENSION);
	return (open(file, O_RDONLY));
}

void	ft_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
}
