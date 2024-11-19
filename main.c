/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:05:54 by joschmun          #+#    #+#             */
/*   Updated: 2024/11/05 14:05:54 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game)
{
	game->found_coins = 0;
	game->count_coins = 0;
	game->max_y = 0;
	game->max_x = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->enemy_h_x = 0;
	game->enemy_h_y = 0;
	game->enemy_v_x = 0;
	game->enemy_v_y = 0;
	game->direction_v = 1;
	game->direction_h = 1;
	game->enemy_h_dead = 0;
	game->enemy_v_dead = 0;
	game->highscore = 0;
	game->coins_highscore = 0;
	game->kill_highscore = 0;
	game->step_counter = 0;
	game->kill_counter = 0;
	game->gold_rush = 10;
}

int start_game(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}

int error(t_game *game)
{
	find_positions(game);
	find_positions_Y(game);
	find_positions_X(game);
	count_coins(game);
	if (game->count_coins == 0)
	{
		perror("Error\nno coins\n");
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	char **test_map;
	t_game game;
	if (argc != 2)
		return (1);
	init_game(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	if (init_window_and_map(&game, argv[argc - 1]) || create_window(&game) || \
		error(&game))
	{
		free(game.map);
		free(game.mlx);
		return (1);
	}
	test_map = ft_copy_map(game.max_y, game.max_x, game.map);
	if (!test_map)
	{
		perror("Error\nfailed to copy map");
		free(game.map);
		free(game.mlx);
		return (1);
	}
	if (ft_validate_map(test_map, game.max_y, game.max_x))
		return (1);
	mlx_hook(game.win, 17, 0, close_window, &game);
	load_game_assets(&game);
	ft_title_screen();
	start_game(&game);
	free(game.map);
	free(game.mlx);
	return (0);
}
