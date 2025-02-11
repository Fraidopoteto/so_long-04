/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:48:00 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/16 22:29:52 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void render_cell(t_game *game, int x, int y)
{
	void *img = NULL;
	char cell = game->map[y][x];
	img = render_hud00(game, x, y);
	if (cell == '1')
		img = game->textures.wall;
	else if (cell == 'P')
		img = game->textures.player;
	else if (cell == 'C')
		img = game->textures.coin;
	else if (cell == 'E')
		img = game->textures.exit;
	else if (cell == '0')
		img = game->textures.floor;
	else if (cell == 'Y')
		img = game->textures.enemy_y;
	else if (cell == 'X')
		img = game->textures.enemy_x;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
	else
		printf("\nError\ncant find img for map[%d][%d]\n", y, x);
}
void *render_hud00(t_game *game, int x, int y)
{
	char cell = game->map[y][x];
	if (cell == 'O')
		return (game->HUD_textures.zero);
	else if (cell == '!')
		return (game->HUD_textures.one);
	else if (cell == '2')
		return (game->HUD_textures.two);
	else if (cell == '3')
		return (game->HUD_textures.three);
	else if (cell == '4')
		return (game->HUD_textures.four);
	else if (cell == '5')
		return (game->HUD_textures.five);
	else if (cell == '6')
		return (game->HUD_textures.six);
	else if (cell == '7')
		return (game->HUD_textures.seven);
	else if (cell == '8')
		return (game->HUD_textures.eight);
	else if (cell == '9')
		return (game->HUD_textures.nine);
	else if (cell == 'x')
		return (game->HUD_textures.HUD_heart);
	return (NULL);
}

void render_row(t_game *game, int y)
{
	int x;

	x = 0;
	while (x < game->max_x)
	{
		render_cell(game, x, y);
		x++;
	}
}

void render_map(t_game *game)
{
	int y;

	y = 0;
	while (y < game->max_y)
	{
		render_row(game, y);
		y++;
	}
}
int load_game_assets(t_game *game)
{
	game->textures = load_textures(game->mlx);
	game->HUD_textures = load_HUD_textures00(game->mlx);
	render_map(game);
	return (0);
}
