/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:48:48 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/28 09:49:23 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_rectangular(char **map, t_game *game)
{
	int		i;

	if (!map || !map[0])
		return (0);
	game->map_width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != game->map_width)
			return (0);
		i++;
	}
	return (1);
}

int	has_valid_borders(char **map)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || !map[i + 1]) && map[i][j] != '1')
				return (0);
			if ((j == 0 || j == len - 1) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_elements(char c, t_game *game, int x, int y)
{
	if (c == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->player++;
	}
	else if (c == 'E')
		game->exits++;
	else if (c == 'C')
		game->items++;
	else if (c != '0' && c != '1' && c != 'G')
		return (0);
	return (1);
}

int	has_required_elements(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!count_elements(map[i][j], game, j, i))
				return (0);
			j++;
		}
		i++;
	}
	return (game->player == 1 && game->exits == 1 && game->items >= 1);
}

int	validate_map(char **map, t_game	*game)
{
	char		**map_copy;

	if (!is_rectangular(map, game))
		return (0);
	if (!has_valid_borders(map))
		return (0);
	if (!has_required_elements(map, game))
		return (0);
	game->items_check = game->items;
	game->exits_check = game->exits;
	map_copy = duplicate_map(map);
	if (!flood_fill(map_copy, game->player_x, game->player_y, game))
	{
		free_map(map_copy);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
