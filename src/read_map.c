/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:26:19 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/26 11:48:58 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *filename, t_game *game)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game->map_height = count_lines(fd);
	close(fd);
	if (game->map_height == 0)
		return (NULL);
	map = allocate_map(filename, game);
	return (map);
}

char	**allocate_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		cleanup(game, map, NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < game->map_height)
	{
		line = strip_newline(line);
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	*strip_newline(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

size_t	count_lines(int fd)
{
	char	*line;
	size_t	count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

char	**free_map(char **map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
