/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:26:10 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/27 17:52:09 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# define TILE_SIZE 45
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307


typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*wall;
	void	*character;
	void	*character_left;
	void	*character_down;
	void	*character_up;
	void	*character_sprite;	
	void	*item;
	void	*exit;
	void	*floor;
	void	*ghost;
	int		player_x;
	int		player_y;
	int		player;
	size_t	map_width;
	int		map_height;
	int		tile_width;
	int		tile_height;
	int		items;
	int		items_check;
	int		exits_check;
	int		items_collected;
	int		window_width;
	int		window_height;
	int		exits;
	int		move_count;
}	t_game;

char	**allocate_map(char *filename, t_game *game);
char	**duplicate_map(char **map);
char	**free_map(char **map);
char	**read_map(char *filename, t_game *game);
char	*get_next_line(int fd);
char	*strip_newline(char *line);
int		close_window(t_game *game);
int		count_elements(char c, t_game *game, int x, int y);
int		flood_fill(char **map, int x, int y, t_game *game);
int		has_required_elements(char **map, t_game *game);
int		has_valid_borders(char **map);
int		is_rectangular(char **map, t_game *game);
int		key_press(int keycode, t_game *game);
int		validate_map(char **map, t_game *game);
int		valid_format(char *str);
size_t	count_lines(int fd);
void	calculate_new_position(int keycode, size_t *new_x, int *new_y);
void	cleanup(t_game *game, char **map, char *error_message);
void	display_move_count(t_game *game);
void	init_window(t_game *game);
void	load_image(t_game *game, void **image, char *path);
void	load_images(t_game *game);
void	move_player(int keycode, t_game *game);
void	render_map(t_game *game, char **map);
void	render_tile(t_game *game, size_t x, int y, int keycode);


#endif
