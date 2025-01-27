/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:48:34 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/27 07:17:39 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

#include "so_long.h"

void	render_tile(t_game *game, size_t x, int y)
{
	void	*img;

	img = NULL;
	if (game->map[y][x] == 'P')
		img = game->character;
	else if (game->map[y][x] == '1')
		img = game->wall;
	else if (game->map[y][x] == 'C')
		img = game->item;
	else if (game->map[y][x] == 'E')
		img = game->exit;
	else if (game->map[y][x] == '0')
		img = game->exit;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, \
			x * game->tile_width, y * game->tile_height);
}

void	move_player(int keycode, t_game *game)
{
	size_t	new_x;
	int		new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	calculate_new_position(keycode, &new_x, &new_y);
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
		{
			game->items_collected++;
			game->map[new_y][new_x] = '0';
		}
		else if (game->map[new_y][new_x] == 'E' && \
			game->items_collected == game->items)
			cleanup(game, game->map, "You won\n");

		if (game->map[new_y][new_x] != 'E')
		{
			game->map[game->player_y][game->player_x] = '0';
			render_tile(game, game->player_x, game->player_y);
			game->player_x = new_x;
			game->player_y = new_y;
			game->map[game->player_y][game->player_x] = 'P';
			render_tile(game, game->player_x, game->player_y);
			game->move_count++;
			ft_printf(" Moves: %d\n", game->move_count);
		}
	}
}
