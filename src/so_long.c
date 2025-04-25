/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:55 by rgu               #+#    #+#             */
/*   Updated: 2025/04/25 23:17:02 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

int	handler_exit(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	exit_game(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error of arguments\n");
		return (1);
	}
	if (load_map(argv[1], &game) == 0)
	{
		ft_printf("Error loading map\n");
		free_map(game.map);
		return (1);
	}
	if (validate_map(game.map) == 0)
	{
		free_map(game.map);
		return (1);
	}
	init_game(&game);
	draw_map(&game);
	mlx_key_hook (game.win, handle_key, &game);
	mlx_expose_hook(game.win, draw_map_wrapper, &game);
	mlx_hook(game.win, 17, 0, handler_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
