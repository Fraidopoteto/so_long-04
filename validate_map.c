/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:10:09 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/16 22:39:51 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int y, int max_y, int x, int max_x, int *found_exit)
{
	if (y < 0 || y >= max_y || x < 0 || x >= max_x)
		return;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	if (map[y][x] == 'E')
	{
		(*found_exit)++;
		return;
	}
	map[y][x] = 'V';
	ft_flood_fill(map, y + 1, max_y, x, max_x, found_exit);
	ft_flood_fill(map, y - 1, max_y, x, max_x, found_exit);
	ft_flood_fill(map, y, max_y, x + 1, max_x, found_exit);
	ft_flood_fill(map, y, max_y, x - 1, max_x, found_exit);
}

int	ft_check_walls(char **map, int max_y, int max_x)
{
	int y;
	int x;

	y = 1;
	x = 0;
	while(x < max_x)
	{
		if (map[1][x] != '1')
		{
			printf("Error\nno walls00\n");
			return (1);
		}
		x++;
	}
	x = 0;
	while(map[max_y - 1][x])
	{
		if (map[max_y - 1][x] != '1')
		{
			printf("Error\nno walls01\n");
			return (1);
		}
		x++;
	}
	while(y < max_y)
	{
		if (map[y][0] != '1' || map[y][max_x - 1] != '1')
		{
			printf("Error\nno walls02\n");
			return (1);
		}
		y++;
	}
	return (0);
}


int	ft_validate_map(char **map, int max_y, int max_x)
{
	int start_y;
	int start_x;
	int y;
	int x;
	int found_exit;

	start_y = 0;
	start_x = 0;
	found_exit = 0;
	y = 0;
	x = 0;
	while (y < max_y)
	{
		while (x < max_x)
		{
			if (map[y][x] == 'P')
			{
				start_y = y;
				start_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if ((start_y == 0) && (start_x == 0))
	{
		printf("Error\nno player\n");
		return (1);
	}
	ft_flood_fill(map, start_y, max_y, start_x, max_x, &found_exit);
	if (found_exit < 1 || ft_check_walls(map, max_y, max_x))
	{
		printf("Error\nnot reachable00\n");
		return(1);
	}
	x = 0;
	y = 0;
	while (y < max_y)
	{
		while (x < max_x)
		{
			if (map[y][x] == 'C')
			{
				printf("Error\nnot reachable01\n");
				return(1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}



