#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "../include/key_code.h"

void	move_player(t_game *game, int move_x, int move_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + move_y;
	new_y = game->player_y + move_x;
	if (game->map[new_x][new_y] == '1')
		return ;
	if (game->map[new_x][new_y] == 'C')
		game->collectibles--;
	if (game->map[new_x][new_y] == 'E' && game->collectibles == 0)
	{
		printf("you win! your total move is: %d", game->moves);
		exit_game(game);
	}
	if (game->map[new_x][new_y] == 'E' && game->collectibles > 0)
		return ;
	game->moves++;
	game->map[game->player_x][game->player_y] = '0';
	game->map[new_x][new_y] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	printf("total moves: %d\n", game->moves);
	draw_map(game);
}

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}
