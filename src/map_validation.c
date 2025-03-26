#include "../include/so_long.h"
#include "../libft/libft.h"

int	is_rectangular(char **map)
{
	size_t	width;
	int		i;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_wall(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = 0;
	j = 0;
	height = 0;
	width = ft_strlen(map[i]);
	while (map[height])
		height++;
	while (j <= width - 1)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (i > 0 && i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_necessary_elements_aux(char **map,
		int player, int exit, int collect)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collect++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (player == 1 && exit == 1 && collect > 0);
}

int	check_necesary_elements(char **map)
{
	int	player;
	int	exit;
	int	collect;

	player = 0;
	exit = 0;
	collect = 0;
	return (check_necessary_elements_aux(map, player, exit, collect));
}

int	validate_map(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	if (!is_rectangular(map) || !is_surrounded_by_wall(map)
		|| !check_necesary_elements(map))
		return (0);
	if (!map_is_playable(map, height))
		return (0);
	return (1);
}
