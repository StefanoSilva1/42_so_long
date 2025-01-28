/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:48:34 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/28 10:24:05 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		cleanup(game, game->map, "Game closed.\n");
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S \
			|| keycode == KEY_D || keycode == KEY_UP \
			|| keycode == KEY_LEFT || keycode == KEY_DOWN \
			|| keycode == KEY_RIGHT)
		move_player(keycode, game);
	return (0);
}

void	calculate_new_position(int keycode, size_t *new_x, int *new_y)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
		(*new_x)--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		(*new_x)++;
	else if (keycode == KEY_W || keycode == KEY_UP)
		(*new_y)--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		(*new_y)++;
}

void	render_tile(t_game *game, size_t x, int y, int keycode)
{
	void	*img;

	img = NULL;
	if (game->map[y][x] == 'P' && (keycode == KEY_D || keycode == KEY_RIGHT))
		img = game->character;
	if (game->map[y][x] == 'P' && (keycode == KEY_A || keycode == KEY_LEFT))
		img = game->character_left;
	if (game->map[y][x] == 'P' && (keycode == KEY_S || keycode == KEY_DOWN))
		img = game->character_down;
	else if (game->map[y][x] == 'P' && (keycode == KEY_W || keycode == KEY_UP))
		img = game->character_up;
	else if (game->map[y][x] == '1')
		img = game->wall;
	else if (game->map[y][x] == 'C')
		img = game->item;
	else if (game->map[y][x] == 'E')
		img = game->exit;
	else if (game->map[y][x] == '0')
		img = game->floor;
	else if (game->map[y][x] == 'G')
		img = game->ghost;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, \
			x * game->tile_width, y * game->tile_height);
}

void	display_move_count(t_game *game)
{
	char	*move_str;

	mlx_put_image_to_window(game->mlx, game->win, game->wall, \
			0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->wall, \
			45, 0);
	move_str = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->win, 5, 12, 0x000000, "MOVES:");
	mlx_string_put(game->mlx, game->win, 47, 12, 0x000000, move_str);
	free(move_str);
}
