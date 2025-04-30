/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/30 00:33:14 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_check(9, "Error\nCouldn't connect with Xserver!\n", 1, game);
	game->window = mlx_new_window(game->mlx, (game->map->width * 64),
			(game->map->height * 64), "The Evil Queen Game!");
	if (game->window == NULL)
	{
		free(game->mlx);
		error_check(10, "Error\nCouldn't open the window!\n", 1, game);
	}
}

void	gameplay(t_game *game)
{
	mlx_set_font(game->mlx, game->window, "6x10");
	mlx_loop_hook(game->mlx, no_input, game);
	mlx_key_hook(game->window, key_pressed, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, x_press, game);
	mlx_loop(game->mlx);
}

int	no_input(t_game *game)
{
	put_exit(game->map, game, game->spt);
	return (1);
}

int	x_press(t_game *game)
{
	ft_printf("You closed the game =/\n");
	free_for_finish(game->map, game);
	return (1);
}

int	key_pressed(int key, t_game *game)
{
	if (key == XK_Escape)
		x_press(game);
	else if (key == XK_d || key == XK_Right)
		step_right(game->map, game);
	else if (key == XK_a || key == XK_Left)
		step_left(game->map, game);
	else if (key == XK_w || key == XK_Up)
		step_up(game->map, game);
	else if (key == XK_s || key == XK_Down)
		step_down(game->map, game);
	print_steps(game);
	return (1);
}
