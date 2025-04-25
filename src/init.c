/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:36 by rgu               #+#    #+#             */
/*   Updated: 2025/04/26 01:06:03 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	load_image(t_game *game)
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
	if (!game->img_collect || !game->img_exit || !game->img_exit
		|| !game->img_floor || !game->img_player || !game->img_wall)
		return (0);
	return (1);
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

static int	init_mlx_and_screen(t_game *game)
{
	int	screen_width;
	int	screen_height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: MLX init failed\n");
		return (0);
	}
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if (game->width * TILE_SIZE > screen_width
		|| game->height * TILE_SIZE > screen_height)
	{
		ft_printf("Error\nMap too big for screen\n");
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	return (1);
}

void	init_game(t_game *game)
{
	if (init_mlx_and_screen(game) == 0)
	{
		free_map(game->map);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		ft_printf("Error: Window creation failed\n");
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(game->map);
		exit(1);
	}
	if (load_image(game) == 0)
	{
		exit_game(game, 1);
		ft_printf("Error: Image load failed\n");
	}
	game->moves = 0;
	find_player(game);
	game->collectibles = count_collectible(game->map);
}
