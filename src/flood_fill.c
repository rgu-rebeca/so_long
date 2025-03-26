#include "../include/so_long.h"
#include "../libft/libft.h"

static char	**copy_map(char **map, int height)
{
	int		i;
	char	**copied_map;

	i = 0;
	copied_map = malloc(sizeof(char *) * (height + 1));
	if (!copied_map)
		return (NULL);
	while (i < height)
	{
		copied_map[i] = ft_strdup(map[i]);
		i++;
	}
	copied_map[i] = NULL;
	return (copied_map);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'F')
		return ;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static void	find_player(char **map, int *px, int *py)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				*px = x;
				*py = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static int	check_flood_result(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_is_playable(char **map, int height)
{
	int		px;
	int		py;
	char	**copy;
	int		result;
	int		i;

	px = 0;
	py = 0;
	i = 0;
	copy = copy_map(map, height);
	find_player(copy, &px, &py);
	flood_fill(copy, px, py);
	result = check_flood_result(copy);
	if (result == 0)
		return (0);
	while (i < height - 1)
		free(copy[i++]);
	free(copy);
	return (1);
}
