/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:26:25 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/27 09:30:43 by sdavi-al         ###   ########.fr       */
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
	load_image(game, &game->wall, "wall.xpm");
	load_image(game, &game->item, "item.xpm");
	load_image(game, &game->exit, "exit.xpm");
	load_image(game, &game->floor, "floor.xpm");
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
			img = NULL;
			if (map[y][x] == 'P')
				img = game->character;
			else if (map[y][x] == '1')
				img = game->wall;
			else if (map[y][x] == 'C')
				img = game->item;
			else if (map[y][x] == 'E')
				img = game->exit;
			else if (map[y][x] == '0')
				img = game->floor;
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, \
					x * game->tile_width, y * game->tile_height);
			x++;
		}
		y++;
	}
}
