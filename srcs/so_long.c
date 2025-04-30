/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/29 19:56:53 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_sprite	spt;

	game.map = &map;
	game.spt = &spt;
	map.file = argv[1];
	game.steps = 0;
	valid_open_map(argc, map.file, &map);
	get_map_size(&map);
	allocs(&map);
	valid_map_draw(&map);
	game_init(&game);
	take_sprites(&game, &spt);
	fill_map(&map, &game);
	gameplay(&game);
}

// valid_open_map does a map validation to start the game