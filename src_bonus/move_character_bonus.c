/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:48:34 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/27 18:01:26 by sdavi-al         ###   ########.fr       */
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
	else if (game->map[y][x] == 'P' && (keycode == KEY_A || keycode == KEY_LEFT))
		img = game->character_left;
	else if (game->map[y][x] == 'P' && (keycode == KEY_S || keycode == KEY_DOWN))
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
			cleanup(game, game->map, "You Win\n");
		else if (game->map[new_y][new_x] == 'G')
			cleanup(game, game->map, "You lose\n");
		if (game->map[new_y][new_x] != 'E')
		{
			game->map[game->player_y][game->player_x] = '0';
			render_tile(game, game->player_x, game->player_y, keycode);
			game->player_x = new_x;
			game->player_y = new_y;
			game->map[game->player_y][game->player_x] = 'P';
			render_tile(game, game->player_x, game->player_y, keycode);
			game->move_count++;
			display_move_count(game);
		}
	}
}
