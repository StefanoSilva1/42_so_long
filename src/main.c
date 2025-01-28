/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:26:25 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/28 09:47:46 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		cleanup(&game, NULL, "Error\nInvalid number of arguments\n");
	if (!valid_format(argv[1]))
		cleanup(&game, NULL, "Error\nInvalid Format\n");
	map = read_map(argv[1], &game);
	if (!map || !validate_map(map, &game))
		cleanup(&game, map, "Error\nInvalid map\n");
	game.map = map;
	init_window(&game);
	render_map(&game, map);
	mlx_hook(game.win, 2, 1, key_press, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	cleanup(&game, map, NULL);
	return (0);
}
