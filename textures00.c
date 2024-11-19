/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:14:57 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/16 16:17:34 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures load_textures(void *mlx)
{
	t_textures textures;
	int img_width, img_height;

	textures.wall = mlx_xpm_file_to_image(mlx, "sprites/kaktus04.xpm", &img_width, &img_height);
	textures.player = mlx_xpm_file_to_image(mlx, "sprites/cowboy_knife00.xpm", &img_width, &img_height);
	textures.floor = mlx_xpm_file_to_image(mlx, "sprites/floor00.xpm", &img_width, &img_height);
	textures.exit = mlx_xpm_file_to_image(mlx, "sprites/chest02.xpm", &img_width, &img_height);
	textures.coin = mlx_xpm_file_to_image(mlx, "sprites/coin02.xpm", &img_width, &img_height);
	textures.enemy_y = mlx_xpm_file_to_image(mlx, "sprites/cowboy_Y00.xpm", &img_width, &img_height);
	textures.enemy_x = mlx_xpm_file_to_image(mlx, "sprites/cowboy_X00.xpm", &img_width, &img_height);
	return (textures);
}

t_HUD_textures load_HUD_textures00(void *mlx)
{
	t_HUD_textures HUD_textures;
	int img_width, img_height;

	HUD_textures.zero = mlx_xpm_file_to_image(mlx, "sprites/number00.xpm", &img_width, &img_height);
	HUD_textures.one = mlx_xpm_file_to_image(mlx, "sprites/number01.xpm", &img_width, &img_height);
	HUD_textures.two = mlx_xpm_file_to_image(mlx, "sprites/number02.xpm", &img_width, &img_height);
	HUD_textures.three = mlx_xpm_file_to_image(mlx, "sprites/number03.xpm", &img_width, &img_height);
	HUD_textures.four = mlx_xpm_file_to_image(mlx, "sprites/number04.xpm", &img_width, &img_height);
	HUD_textures.five = mlx_xpm_file_to_image(mlx, "sprites/number05.xpm", &img_width, &img_height);
	HUD_textures.six = mlx_xpm_file_to_image(mlx, "sprites/number06.xpm", &img_width, &img_height);
	HUD_textures.seven = mlx_xpm_file_to_image(mlx, "sprites/number07.xpm", &img_width, &img_height);
	HUD_textures.eight = mlx_xpm_file_to_image(mlx, "sprites/number08.xpm", &img_width, &img_height);
	HUD_textures.nine = mlx_xpm_file_to_image(mlx, "sprites/number09.xpm", &img_width, &img_height);
	HUD_textures.HUD_heart = mlx_xpm_file_to_image(mlx, "sprites/HUD_heart00.xpm", &img_width, &img_height);
	return (HUD_textures);
}
// t_HUD_textures load_HUD_textures01(void *mlx)
// {
// 	t_HUD_textures HUD_textures;
// 	int img_width, img_height;
// 	HUD_textures.zero_left = mlx_xpm_file_to_image(mlx, "sprites/number_left00.xpm", &img_width, &img_height);
// 	HUD_textures.one_left = mlx_xpm_file_to_image(mlx, "sprites/number_left01.xpm", &img_width, &img_height);
// 	HUD_textures.two_left = mlx_xpm_file_to_image(mlx, "sprites/number_left02.xpm", &img_width, &img_height);
// 	HUD_textures.three_left = mlx_xpm_file_to_image(mlx, "sprites/number_left03.xpm", &img_width, &img_height);
// 	HUD_textures.four_left = mlx_xpm_file_to_image(mlx, "sprites/number_left04.xpm", &img_width, &img_height);
// 	HUD_textures.five_left = mlx_xpm_file_to_image(mlx, "sprites/number_left05.xpm", &img_width, &img_height);
// 	HUD_textures.six_left = mlx_xpm_file_to_image(mlx, "sprites/number_left06.xpm", &img_width, &img_height);
// 	HUD_textures.seven_left = mlx_xpm_file_to_image(mlx, "sprites/number_left07.xpm", &img_width, &img_height);
// 	HUD_textures.eight_left = mlx_xpm_file_to_image(mlx, "sprites/number_left08.xpm", &img_width, &img_height);
// 	HUD_textures.nine_left = mlx_xpm_file_to_image(mlx, "sprites/number_left09.xpm", &img_width, &img_height);
// 	HUD_textures.HUD_coin = mlx_xpm_file_to_image(mlx, "sprites/HUD_coin00.xpm", &img_width, &img_height);
// 	return (HUD_textures);
// }
// t_HUD_textures load_HUD_textures02(void *mlx)
// {
// 	t_HUD_textures HUD_textures;
// 	int img_width, img_height;
// 	HUD_textures.zero_right = mlx_xpm_file_to_image(mlx, "sprites/number_right00.xpm", &img_width, &img_height);
// 	HUD_textures.one_right = mlx_xpm_file_to_image(mlx, "sprites/number_right01.xpm", &img_width, &img_height);
// 	HUD_textures.two_right = mlx_xpm_file_to_image(mlx, "sprites/number_right02.xpm", &img_width, &img_height);
// 	HUD_textures.three_right = mlx_xpm_file_to_image(mlx, "sprites/number_right03.xpm", &img_width, &img_height);
// 	HUD_textures.four_right = mlx_xpm_file_to_image(mlx, "sprites/number_right04.xpm", &img_width, &img_height);
// 	HUD_textures.five_right = mlx_xpm_file_to_image(mlx, "sprites/number_right05.xpm", &img_width, &img_height);
// 	HUD_textures.six_right = mlx_xpm_file_to_image(mlx, "sprites/number_right06.xpm", &img_width, &img_height);
// 	HUD_textures.seven_right = mlx_xpm_file_to_image(mlx, "sprites/number_right07.xpm", &img_width, &img_height);
// 	HUD_textures.eight_right = mlx_xpm_file_to_image(mlx, "sprites/number_right08.xpm", &img_width, &img_height);
// 	HUD_textures.nine_right = mlx_xpm_file_to_image(mlx, "sprites/number_right09.xpm", &img_width, &img_height);
// 	HUD_textures.HUD_shoe = mlx_xpm_file_to_image(mlx, "sprites/HUD_shoes00.xpm", &img_width, &img_height);
// 	return (HUD_textures);
// }
// void *render_hud01(t_game *game, int x, int y)
// {
// 	char cell = game->map[y][x];
// 	if (cell == 'a')
// 		return (game->HUD_textures.zero_left);
// 	else if (cell == 'b')
// 		return (game->HUD_textures.one_left);
// 	else if (cell == 'c')
// 		return (game->HUD_textures.two_left);
// 	else if (cell == 'd')
// 		return (game->HUD_textures.three_left);
// 	else if (cell == 'e')
// 		return (game->HUD_textures.four_left);
// 	else if (cell == 'f')
// 		return (game->HUD_textures.five_left);
// 	else if (cell == 'g')
// 		return (game->HUD_textures.six_left);
// 	else if (cell == 'h')
// 		return (game->HUD_textures.seven_left);
// 	else if (cell == 'i')
// 		return (game->HUD_textures.eight_left);
// 	else if (cell == 'j')
// 		return (game->HUD_textures.nine_left);
// 	else if (cell == 'y')
// 		return (game->HUD_textures.HUD_coin);
// 	return (NULL);
// }
// void *render_hud02(t_game *game, int x, int y)
// {
// 	char cell = game->map[y][x];
// 	if (cell == 'k')
// 		return (game->HUD_textures.zero);
// 	else if (cell == 'l')
// 		return (game->HUD_textures.one);
// 	else if (cell == 'm')
// 		return (game->HUD_textures.two);
// 	else if (cell == 'n')
// 		return (game->HUD_textures.three);
// 	else if (cell == 'o')
// 		return (game->HUD_textures.four);
// 	else if (cell == 'p')
// 		return (game->HUD_textures.five);
// 	else if (cell == 'q')
// 		return (game->HUD_textures.six);
// 	else if (cell == 'r')
// 		return (game->HUD_textures.seven);
// 	else if (cell == 's')
// 		return (game->HUD_textures.eight);
// 	else if (cell == 'd')
// 		return (game->HUD_textures.nine);
// 	else if (cell == 'z')
// 		return (game->HUD_textures.HUD_shoe);
// 	return (NULL);
// }
