/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/30 00:49:15 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <../libs/minilibx/mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAP_CHARS "01CEP"

# define PERSON_D "assets/queen_d.xpm"
# define PERSON_L "assets/queen_l.xpm"
# define PERSON_R "assets/queen_r.xpm"
# define PERSON_U "assets/queen_u.xpm"
# define EXIT "assets/exit.xpm"
# define GROUND "assets/bg.xpm"
# define WALL "assets/bush.xpm"
# define COIN "assets/apple.xpm"

typedef struct s_map
{
	char	*file;
	int		fd;
	char	**map;
	int		size;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		coin;
	int		coin_count;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		path_check;
	int		check_format;
}			t_map;

typedef struct s_sprite
{
	void	*person_d;
	void	*person_l;
	void	*person_r;
	void	*person_u;
	void	*exit;
	void	*ground;
	void	*wall;
	void	*coin;
	void	*zombie;
}			t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			img_width;
	int			img_height;
	int			steps;
	t_sprite	*spt;
	t_map		*map;
}			t_game;

void	valid_open_map(int argc, char *map_path, t_map *map);
void	get_map_size(t_map *map);
void	allocs(t_map *map);
void	valid_map_draw(t_map *map);
void	draw_map(t_map *map);
int		check_for_wall_surround(t_map *map);
int		check_for_player(t_map *map);
int		check_for_exit(t_map *map);
int		check_for_coins(t_map *map);
int		check_for_dif_char(t_map *map);
void	copy_map(t_map *copy, t_map *map);
void	get_map_path(t_map *map, int y, int x);
void	read_map_lines(t_map *map);
void	validate_map_size(t_map *map);
void	validate_map_requirements(t_map *map);
void	initialize_copy_map(t_map *copy, t_map *map);
void	validate_map_paths(t_map *copy, t_map *map);
void	read_map(t_map *map, char *temp);

void	game_init(t_game *game);
void	take_sprites(t_game *game, t_sprite *spt);

void	fill_map(t_map *map, t_game *game);
void	put_player(t_map *map, t_game *game, t_sprite *spt, char direction);
void	put_coin(t_map *map, t_game *game, t_sprite *spt);
void	put_wall_and_ground(t_map *map, t_game *game, t_sprite *spt);
void	put_exit(t_map *map, t_game *game, t_sprite *spt);
void	print_steps(t_game *game);

void	gameplay(t_game *game);
void	step_right(t_map *map, t_game *game);
void	step_left(t_map *map, t_game *game);
void	step_up(t_map *map, t_game *game);
void	step_down(t_map *map, t_game *game);
void	try_move_player(t_map *map, t_game *game, int dx, int dy);
void	handle_exit(t_map *map, t_game *game, int dx, int dy);
void	handle_move(t_map *map, t_game *game, int dx, int dy);

int		no_input(t_game *game);
int		key_pressed(int key, t_game *game);
int		x_press(t_game *game);

void	free_map(t_map *map);
void	free_images(t_game *game);
void	free_exit(t_game *game);
void	free_mlx(t_game *game);
void	free_for_finish(t_map *map, t_game *game);
void	error_check(int i, char *errormsg, int program_stage, t_game *game);
void	handle_victory(t_map *map, t_game *game, t_sprite *spt);
void	handle_game_over(t_map *map, t_game *game, t_sprite *spt);

#endif