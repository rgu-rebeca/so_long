/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:36 by rgu               #+#    #+#             */
/*   Updated: 2025/04/25 23:35:01 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

void	load_image(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "asset/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"asset/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"asset/player.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"asset/object.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"asset/exit.xpm", &w, &h);
}

void	find_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

int	count_collectible(char **map)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void	init_game(t_game *game)
{
	int	screen_width;
	int	screen_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_printf("mlx falied");
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if (game->width * TILE_SIZE > screen_width || game->height * TILE_SIZE > screen_height)
	{
		ft_printf("Error\nThe map is too big for the screen.\n");
		free_map(game->map);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		ft_printf("win failed");
		exit (1);
	}
	game->moves = 0;
	find_player(game);
	game->collectibles = count_collectible(game->map);
	load_image(game);
}
