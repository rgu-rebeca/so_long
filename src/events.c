/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:23 by rgu               #+#    #+#             */
/*   Updated: 2025/04/26 01:03:46 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../include/key_code.h"

void	move_player(t_game *game, int move_x, int move_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + move_x;
	new_y = game->player_y + move_y;
	if (game->map[new_x][new_y] == '1')
		return ;
	if (game->map[new_x][new_y] == 'C')
		game->collectibles--;
	if (game->map[new_x][new_y] == 'E' && game->collectibles == 0)
	{
		ft_printf("you win! your total move is: %d\n", game->moves);
		exit_game(game, 0);
	}
	if (game->map[new_x][new_y] == 'E' && game->collectibles > 0)
		return ;
	game->moves++;
	game->map[game->player_x][game->player_y] = '0';
	game->map[new_x][new_y] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	ft_printf("total moves: %d\n", game->moves);
	draw_map(game);
}

void	exit_game(t_game *game, int exit_code)
{
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(exit_code);
}

int	handle_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		exit_game(game, 0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_player(game, -1, 0);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_player(game, 1, 0);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_player(game, 0, -1);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_player(game, 0, 1);
	return (0);
}
