/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:18:43 by misimon           #+#    #+#             */
/*   Updated: 2022/09/29 17:54:21 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_size	get_cord(char **map, t_size object_cord)
{
	int	i[2];
	int	check;

	check = 0;
	i[0] = 0;
	while (map[i[0]] && check != 1)
	{
		i[1] = 0;
		while (map[i[0]][i[1]] && check != 1)
		{
			if (map[i[0]][i[1]] == 'C' || map[i[0]][i[1]] == 'E')
			{
				map[i[0]][i[1]] = 'X';
				object_cord.y = i[0];
				object_cord.x = i[1];
				check = 1;
			}
			i[1]++;
		}
		i[0]++;
	}
	return (object_cord);
}

char	**copy_map(char **map)
{
	char	**new;
	int		i;
	int		j;
	int		l;

	l = ft_strlen(map[0]) + 1;
	i = 0;
	while (map[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (map[++i])
	{
		new[i] = malloc(sizeof(char) * l);
		j = -1;
		while (map[i][++j])
			new[i][j] = map[i][j];
		new[i][j] = '\0';
	}
	new[i] = 0;
	return (new);
}

int	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (1);
}

int	player_access(int x, int y, char **map, t_size player)
{
	char	**copy;

	copy = copy_map(map);
	if (player.x == x && player.y == y)
		return (free_map(copy));
	copy[y][x] = '1';
	if (map[y][x - 1] != '1')
		if (player_access(x - 1, y, copy, player))
			return (free_map(copy));
	if (map[y - 1][x] != '1')
		if (player_access(x, y - 1, copy, player))
			return (free_map(copy));
	if (map[y][x + 1] != '1')
		if (player_access(x + 1, y, copy, player))
			return (free_map(copy));
	if (map[y + 1][x] != '1')
		if (player_access(x, y + 1, copy, player))
			return (free_map(copy));
	return (free_map(copy) - 1);
}

void	check_access(t_var *mlx)
{
	t_size	object_cord;
	t_size	player;
	char	**map;
	int		max_cord;
	int		i;

	i = 0;
	player.x = mlx->player.x;
	player.y = mlx->player.y;
	max_cord = mlx->object.n_collect + 1;
	map = ft_split(mlx->map.save, '\n');
	while (max_cord--)
	{
		object_cord = get_cord(map, object_cord);
		if (!player_access(object_cord.x, object_cord.y, map, player))
		{
			free(map);
			exit(error_esc("Object is inaccesible !", mlx));
		}
	}
	free(map);
	free(mlx->map.save);
}
