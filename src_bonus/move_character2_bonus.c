/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:23:13 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/28 11:25:10 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_tile_interaction(t_game *game, char tile)
{
	if (tile == 'C')
	{
		game->items_collected++;
	}
	else if (tile == 'E' && game->items_collected == game->items)
	{
		cleanup(game, game->map, "You Win\n");
	}
	else if (tile == 'G')
	{
		cleanup(game, game->map, "Paraphrasing Willie Wonka:\n"
			"You bumped into the ghost, so you get nothing! You lose!\n"
			"Good day, sir!\n");
	}
}

void	update_position(t_game *game, size_t new_x, int new_y, int keycode)
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

void	move_player(int keycode, t_game *game)
{
	size_t	new_x;
	int		new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	calculate_new_position(keycode, &new_x, &new_y);
	if (game->map[new_y][new_x] != '1')
	{
		handle_tile_interaction(game, game->map[new_y][new_x]);
		if (game->map[new_y][new_x] != 'E')
		{
			if (game->map[new_y][new_x] == 'C')
				game->map[new_y][new_x] = '0';
			update_position(game, new_x, new_y, keycode);
		}
	}
}
