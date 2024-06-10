/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:55:12 by dbislimi          #+#    #+#             */
/*   Updated: 2024/06/10 20:28:49 by dbislimi         ###   ########.fr       */
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

# define FLOORXPM "./textures/floor32.xpm"
# define WALLXPM "./textures/wall10.xpm"
# define ONEXITR "./textures/playeronexitr.xpm"
# define ONEXITL "./textures/playeronexitl.xpm"
# define PLAYERRXPM "./textures/playerr.xpm"
# define PLAYERLXPM "./textures/playerl.xpm"
# define COLLECTIBLE1XPM "./textures/coin1.xpm"
# define COLLECTIBLE2XPM "./textures/coin2.xpm"
# define COLLECTIBLE3XPM "./textures/coin3.xpm"
# define COLLECTIBLE4XPM "./textures/coin4.xpm"
# define COLLECTIBLE5XPM "./textures/coin5.xpm"
# define COLLECTIBLE6XPM "./textures/coin6.xpm"
# define COLLECTIBLE7XPM "./textures/coin7.xpm"
# define COLLECTIBLE8XPM "./textures/coin8.xpm"
# define COLLECTIBLE9XPM "./textures/coin9.xpm"
# define EXITXPM "./textures/exit.xpm"
# define EXITOPENXPM "./textures/exitopen.xpm"
# define EXITOPEN1XPM "./textures/exitOpen1.xpm"
# define EXITOPEN2XPM "./textures/exitOpen2.xpm"
# define EXITOPEN3XPM "./textures/exitOpen3.xpm"
# define EXITOPEN4XPM "./textures/exitOpen4.xpm"
# define EXITOPEN5XPM "./textures/exitOpen5.xpm"
# define EXITOPEN6XPM "./textures/exitOpen6.xpm"
# define EXITOPEN7XPM "./textures/exitOpen7.xpm"

enum e_keys
{
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
	ESC = 65307
};

enum e_textures
{
	FLOOR,
	WALL,
	PLAYERR,
	COIN1,
	COIN9 = 11,
	EXIT,
	PLAYERL,
	PLAYERONEXITR,
	PLAYERONEXITL,
	EXITOPEN1,
	EXITOPEN7 = 22
};

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coo;

typedef struct s_map
{
	char	**map;
	int		width;
	int		length;
	int		collectibles;
	t_coo	exit;
	t_coo	player;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	**texture;
	t_map	map_data;
}	t_data;

void	*xpm_to_image(t_data *data, char *name);
void	map_init(char *file, t_data *data);
int		check_for_path(char **map);
int		is_closed(char **map);
int		is_rectangle(char **map);
int		check_filename(char	*file);
char	*ft_strdupforsl(const char *s);
void	ft_exit(char *msg);
void	print_tab(char **tab);
char	**map_dup(char **map);
void	flood_fill(int i, int j, char **map);
int		count_char(char c, char **tab);
t_coo	search_char(char c, char **tab);
void	ft_free(t_data *data, char *msg);
int		on_keypress(int keysym, t_data *data);
int		destroy(t_data *data);
void	load_textures(t_data *data);
void	rendering(t_data *data);
void	change_texture(int texture, char *new_texure, t_data *data);
void	move(int direction, t_data *data);
void	update_position(int direction, t_coo player, t_coo next, t_data *data);
void	put_image(t_data *data, int image, int x, int y);

// BONUS

void	update_coins(t_data *data, int image);
int		sprite(t_data *data);

#endif