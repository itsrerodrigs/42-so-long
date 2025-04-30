/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/30 00:41:20 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_sprites(t_game *game, t_sprite *spt)
{
	spt->person_d = mlx_xpm_file_to_image(game->mlx, PERSON_D, &game->img_width,
			&game->img_height);
	spt->person_l = mlx_xpm_file_to_image(game->mlx, PERSON_L, &game->img_width,
			&game->img_height);
	spt->person_r = mlx_xpm_file_to_image(game->mlx, PERSON_R, &game->img_width,
			&game->img_height);
	spt->person_u = mlx_xpm_file_to_image(game->mlx, PERSON_U, &game->img_width,
			&game->img_height);
	spt->coin = mlx_xpm_file_to_image(game->mlx, COIN, &game->img_width,
			&game->img_height);
	spt->ground = mlx_xpm_file_to_image(game->mlx, GROUND, &game->img_width,
			&game->img_height);
	spt->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->img_width,
			&game->img_height);
	spt->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &game->img_width,
			&game->img_height);
	if (!spt->person_d || !spt->person_l || !spt->person_r || !spt->person_u
		|| !spt->coin || !spt->ground || !spt->wall || !spt->exit)
		error_check(11, "Error\nFail to take images!\n", 2, game);
}
