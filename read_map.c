/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:09:14 by joschmun          #+#    #+#             */
/*   Updated: 2024/11/11 15:09:14 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	**allocate_map_copy(int max_y, int max_x)
{
	char	**map_cpy;
	int		y;

	y = 0;
	map_cpy = malloc(sizeof(char *) * max_y);
	if (!map_cpy)
		return (NULL);
	while (y < max_y)
	{
		map_cpy[y] = malloc(sizeof(char) * (max_x + 1));
		if (!map_cpy[y])
		{
			while (y > 0)
			{
				y--;
				free(map_cpy[y]);
			}
			free(map_cpy);
			return (NULL);
		}
		y++;
	}
	return (map_cpy);
}

char	**ft_copy_map(int max_y, int max_x, char **map)
{
	char	**map_cpy;
	int		y;
	int		x;

	map_cpy = allocate_map_copy(max_y, max_x);
	if (!map_cpy)
		return (NULL);
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			map_cpy[y][x] = map[y][x];
			x++;
		}
		map_cpy[y][x] = '\0';
		y++;
	}
	return (map_cpy);
}


char	**ft_read_map(int fd, int *max_y, int *max_x)
{
	char **map;
	int y;
	int x;
	int line_len;
	char **line_storage;
	char *line;

	y = 0;
	x = 0;
	line_len = 0;
	line_storage = malloc(sizeof(char *) * 1000);
	if (!line_storage)
		return NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		line_storage[*max_y] = line;
		(*max_y)++;
		line_len = 0;
		while (line[line_len] != '\0' && line[line_len] != '\n')
			line_len++;
		if (line_len > *max_x)
			*max_x = line_len;
	}
	map = malloc(sizeof(char *) * (*max_y + 1));
	if (!map)
		return (NULL);
	while (y < *max_y)
	{
		map[y] = malloc(sizeof(char) * (*max_x + 1));
		if (!map[y])
			return NULL;
		x = 0;
		while (line_storage[y][x] != '\0' && line_storage[y][x] != '\n')
		{
			map[y][x] = line_storage[y][x];
			x++;
		}
		map[y][x] = '\0';
		free(line_storage[y]);
		y++;
	}
	free(line_storage);
	map[*max_y] = NULL;
	return (map);
}
