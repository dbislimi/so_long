/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:55:12 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/08 17:12:57 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define BAD_EXTENSION "Error\nBad extension\n"
# define MISSING_FILE "Error\nMissing argument\n"
# define INVALID_MAP "Error\nInvalid map\n"
# define EMPTY_FILE "Error\nEmpty file (or not a file)\n"
# define NOT_FOUND "Error\nNo such file\n"
# define ASSETS "Error\nAssets not found\n"
# define MALLOC "Error\nMalloc Error\n"

# define FLOORxpm "./textures/floor32.xpm"
# define WALLxpm "./textures/wall10.xpm"
# define ONEXITR "./textures/playeronexitr.xpm"
# define ONEXITL "./textures/playeronexitl.xpm"
# define PLAYERRxpm "./textures/playerr.xpm"
# define PLAYERLxpm "./textures/playerl.xpm"
# define COLLECTABLESxpm "./textures/coinn.xpm"
# define EXITxpm "./textures/exit.xpm"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

enum textures
{
	FLOOR,
	WALL,
	PLAYER,
	COINS,
	EXIT,
};

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coo;

typedef struct s_map
{
	char	**save;
	char	**map;
	int		width;
	int		length;
	int		collectables;
	t_coo	exit;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	**texture;
	t_map	map_data;
}	t_data;

void	*xpm_to_image(t_data *data, char *name);
void			map_init(char *file, t_data *data);
int				check_for_path(char **map);
int				is_closed(char **map);
int				is_rectangle(char **map);
int				check_filename(char	*file);
char			*ft_strdupforsl(const char *s);
void			ft_exit(char *msg);
void			print_tab(char **tab);
char			**map_dup(char **map);
void			flood_fill(int i, int j, char **map);
int				count_char(char c, char **tab);
t_coo			search_char(char c, char **tab);
void			ft_free(t_data *data, char *msg);

int				on_keypress(int keysym, t_data *data);
int				destroy(t_data *data);
void			load_textures(t_data *data);
void			rendering(t_data *data);

void	check_texture(int direction, t_coo dest, t_data *data);
void	change_texture(int texture, char *new_texure, t_data *data);
void	move(int direction, t_data *data);
void	update_position(t_coo exit, t_coo current, t_coo new, t_data *data);
#endif