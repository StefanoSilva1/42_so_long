/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:48:16 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/27 10:49:19 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	flood_fill(char **map_copy, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || map_copy[y][x] == '1' || map_copy[y][x] == 'G')
		return (0);
	if (map_copy[y][x] == 'C')
		game->items_check--;
	if (map_copy[y][x] == 'E')
	{
		game->exits_check--;
		return (0);
	}
	map_copy[y][x] = '1';
	flood_fill(map_copy, x + 1, y, game);
	flood_fill(map_copy, x - 1, y, game);
	flood_fill(map_copy, x, y + 1, game);
	flood_fill(map_copy, x, y - 1, game);
	return (game->items_check == 0 && game->exits_check < game->exits);
}

char	**duplicate_map(char **map)
{
	int		i;
	size_t	lines_count;
	char	**map_copy;

	lines_count = 0;
	while (map[lines_count])
		lines_count++;
	map_copy = malloc(sizeof(char *) * (lines_count + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
