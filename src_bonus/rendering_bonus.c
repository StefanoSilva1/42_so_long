/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:26:25 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/28 10:11:09 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_image(t_game *game, void **image, char *path)
{
	*image = mlx_xpm_file_to_image(game->mlx, path, \
		&game->tile_width, &game->tile_height);
	if (!*image)
		cleanup(game, NULL, "Failed to load image\n");
}

void	load_images(t_game *game)
{
	load_image(game, &game->character, "character.xpm");
	load_image(game, &game->character_down, "character_down.xpm");
	load_image(game, &game->character_left, "character_left.xpm");
	load_image(game, &game->character_up, "character_up.xpm");
	load_image(game, &game->wall, "wall.xpm");
	load_image(game, &game->item, "item.xpm");
	load_image(game, &game->exit, "exit.xpm");
	load_image(game, &game->floor, "floor.xpm");
	load_image(game, &game->ghost, "ghost.xpm");
}

void	*get_image_for_tile(t_game *game, char tile)
{
	if (tile == 'P')
		return (game->character);
	else if (tile == '1')
		return (game->wall);
	else if (tile == 'C')
		return (game->item);
	else if (tile == 'E')
		return (game->exit);
	else if (tile == '0')
		return (game->floor);
	else if (tile == 'G')
		return (game->ghost);
	return (NULL);
}

void	render_map(t_game *game, char **map)
{
	size_t	x;
	int		y;
	void	*img;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			img = get_image_for_tile(game, map[y][x]);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, \
					x * game->tile_width, y * game->tile_height);
			x++;
		}
		y++;
	}
}
