/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:59:47 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/27 09:25:32 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_window(t_game *game)
{
	game->tile_width = TILE_SIZE;
	game->tile_height = TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup(game, NULL, " Error\n: Failed to initialize MLX\n");
	game->win = mlx_new_window(game->mlx, game->map_width * game->tile_width, \
		game->map_height * game->tile_height, "so_long");
	if (!game->win)
		cleanup(game, NULL, "Error\n: Failed to initialize MLX\n");
	load_images(game);
}

void	cleanup(t_game *game, char **map, char *error_message)
{
	if (error_message)
		write(2, error_message, ft_strlen(error_message));
	if (map)
		free_map(map);
	if (game->character)
		mlx_destroy_image(game->mlx, game->character);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->item)
		mlx_destroy_image(game->mlx, game->item);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	close_window(t_game *game)
{
	cleanup(game, game->map, NULL);
	return (0);
}
