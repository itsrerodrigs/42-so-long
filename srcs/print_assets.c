/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/30 00:41:22 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_map *map, t_game *game, t_sprite *spt, char direction)
{
	if (direction == 'r')
		mlx_put_image_to_window(game->mlx, game->window, spt->person_r,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'l')
		mlx_put_image_to_window(game->mlx, game->window, spt->person_l,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'u')
		mlx_put_image_to_window(game->mlx, game->window, spt->person_u,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'd')
		mlx_put_image_to_window(game->mlx, game->window, spt->person_d,
			map->player_x * 64, map->player_y * 64);
}

void	put_coin(t_map *map, t_game *game, t_sprite *spt)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, spt->coin,
					x * 64, y * 64);
		}
	}
}

void	put_wall_and_ground(t_map *map, t_game *game, t_sprite *spt)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->window, spt->wall,
					x * 64, y * 64);
			}
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, spt->ground,
					x * 64, y * 64);
		}
	}
}

void	put_exit(t_map *map, t_game *game, t_sprite *spt)
{
	mlx_put_image_to_window(game->mlx, game->window,
		spt->exit, map->exit_x * 64, map->exit_y * 64);
}

void	print_steps(t_game *game)
{
	char	*steps;
	int		len;
	int		x;
	int		y;

	steps = ft_itoa(game->steps);
	len = ft_strlen(steps);
	x = 32 - (len * len);
	y = 30;
	mlx_string_put(game->mlx, game->window, x, y, 0x21ccbb, steps);
	free(steps);
}
