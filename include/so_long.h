#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define TILE_SIZE 64

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_game;

int		load_map(char	*filename, t_game *game);
void	print_map(char **map);
int		map_is_playable(char **map, int height);
int		validate_map(char **map);
void	load_image(t_game *game);
void	init_game(t_game *game);
int		draw_map(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int move_x, int move_y);
void	exit_game(t_game *game);
#endif