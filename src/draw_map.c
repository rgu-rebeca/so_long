#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

static void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, x * TILE_SIZE, y * TILE_SIZE);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, game->img_floor, x, y);
			if (game->map[y][x] == '1')
				draw_tile(game, game->img_wall, x, y);
			else if (game->map[y][x] == 'P')
				draw_tile(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				draw_tile(game, game->img_collect, x, y);
			else if (game->map[y][x] == 'E')
				draw_tile(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
