/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/30 00:41:25 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocs(t_map *map)
{
	int	i;
	int	j;

	map->map = malloc(map->height * sizeof(char *));
	if (map->map == NULL)
		error_check(7, "Error\nFail to allocate memory!", 0, NULL);
	i = -1;
	while (++i < map->height)
	{
		if (i == map->height - 1)
			map->map[i] = malloc((map->width + 1) * sizeof(char));
		else
			map->map[i] = malloc((map->width + 2) * sizeof(char));
		if (map->map[i] == NULL)
		{
			j = -1;
			while (++j < i)
				free(map->map[j]);
			free(map->map);
			error_check(7, "Error\nFail to allocate memory!", 0, NULL);
		}
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free(map->map[i]);
	free(map->map);
}

void	free_mlx(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_images(t_game *game)
{
	if (game->spt->person_d != NULL)
		mlx_destroy_image(game->mlx, game->spt->person_d);
	if (game->spt->person_l != NULL)
		mlx_destroy_image(game->mlx, game->spt->person_l);
	if (game->spt->person_r != NULL)
		mlx_destroy_image(game->mlx, game->spt->person_r);
	if (game->spt->person_u != NULL)
		mlx_destroy_image(game->mlx, game->spt->person_u);
	if (game->spt->coin != NULL)
		mlx_destroy_image(game->mlx, game->spt->coin);
	if (game->spt->wall != NULL)
		mlx_destroy_image(game->mlx, game->spt->wall);
	if (game->spt->ground != NULL)
		mlx_destroy_image(game->mlx, game->spt->ground);
}

void	free_exit(t_game *game)
{
	if (game->spt->exit != NULL)
		mlx_destroy_image(game->mlx, game->spt->exit);
}
