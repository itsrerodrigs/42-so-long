/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/30 00:48:49 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_check(int i, char *errormsg, int program_stage, t_game *game)
{
	if (program_stage >= 1 && game != NULL)
	{
		if (game->map != NULL)
			free_map(game->map);
		if (program_stage == 2)
		{
			if (game->mlx != NULL && game->window != NULL)
				mlx_destroy_window(game->mlx, game->window);
			free_images(game);
			free_exit(game);
			free_mlx(game);
		}
	}
	ft_printf("%s", errormsg);
	exit(i);
}

void	free_for_finish(t_map *map, t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_images(game);
	free_exit(game);
	free_map(map);
	free_mlx(game);
	exit(0);
}

void	handle_victory(t_map *map, t_game *game, t_sprite *spt)
{
	int repeat;
	(void) spt;

	print_steps(game);
	ft_printf("Steps: %d\n", ++game->steps);
	repeat = 0;
	ft_printf("YAY, YOU WIN!!!\n");
	free_for_finish(map, game);
}

void	handle_game_over(t_map *map, t_game *game, t_sprite *spt)
{
	int repeat;
	(void) spt;

	repeat = 0;
	ft_printf("GAME OVER =(\nYou should try again\n");
	free_for_finish(map, game);
}