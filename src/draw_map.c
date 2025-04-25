/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:16 by rgu               #+#    #+#             */
/*   Updated: 2025/04/26 00:25:00 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

static void	draw_tile(t_game *game, void *img, int a, int b)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, a * TILE_SIZE, b * TILE_SIZE);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			draw_tile(game, game->img_floor, y, x);
			if (game->map[x][y] == '1')
				draw_tile(game, game->img_wall, y, x);
			else if (game->map[x][y] == 'P')
				draw_tile(game, game->img_player, y, x);
			else if (game->map[x][y] == 'C')
				draw_tile(game, game->img_collect, y, x);
			else if (game->map[x][y] == 'E')
				draw_tile(game, game->img_exit, y, x);
			y++;
		}
		x++;
	}
	return (1);
}

int	draw_map_wrapper(void *param)
{
	return (draw_map((t_game *)param));
}
