/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:50 by rgu               #+#    #+#             */
/*   Updated: 2025/04/25 22:45:51 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

static int	count_line(char *filename)
{
	int		fd;
	int		count;
	char	c;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("error when open the file\n");
		return (-1);
	}
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count + 1);
}

char	*get_line(int fd)
{
	char	*line;
	int		i;
	char	c;

	i = 0;
	line = malloc(1024);
	if (!line)
		return (close(fd), NULL);
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	load_map(char *filename, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	game->height = count_line(filename);
	if (game->height <= 0)
		return (0);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (close(fd), 0);
	while (i < game->height)
	{
		game->map[i] = get_line(fd);
		if (i == 0)
			game->width = ft_strlen(game->map[i]);
		i++;
	}
	game->map[i] = NULL;
	close (fd);
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free (map[i++]);
	free(map);
}

/*void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}*/