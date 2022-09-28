/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:18:43 by misimon           #+#    #+#             */
/*   Updated: 2022/09/28 20:21:49 by misimon          ###   ########.fr       */
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
		ft_printf("%s\n", map[i[0]]);
		i[0]++;
	}
	return (object_cord);
}

int	player_access(int x, int y, char **map, t_size player)
{
	if (map[y][x - 1] != '1')
		if (player_access(x - 1, y, map, player))
			return (1);
	if (map[y][x + 1] != '1')
		if (player_access(x + 1, y, map, player))
			return (1);
	if (map[y - 1][x] != '1')
		if (player_access(x, y - 1, map, player))
			return (1);
	if (map[y + 1][x] != '1')
		if (player_access(x, y + 1, map, player))
			return (1);
	if (player.x == x && player.y == y)
		return (1);
	return (0);
}

void	check_access(t_var *mlx)
{
	t_size	object_cord;
	t_size	player;
	char 	**map;
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
		ft_printf("y = %d x = %d\n", object_cord.y, object_cord.x);
		if (!player_access(object_cord.x, object_cord.y, map, player))
		{
			free(map);
			exit(error_esc("Object is inaccesible !", mlx));
		}
	}
	free(map);
}

/*
int player_x;
	int player_y;
	int i;
	int map_i;

	i = 0;
	player_x = mlx->player.x;
	player_y = mlx->player.y;
	while (player_y != object_cord[i].y && player_x != object_cord[i].x)
	{
		map_i = -1;

		while (map[++map_i])
			ft_printf("\033[2K\033[1A\r");
		map_i = 0;
		while (map[map_i])
			ft_printf("%s\n", map[map_i++]);
		if (map[player_y - 1][player_x] == '0')
		{
			player_y--;
			map[player_y][player_x] = 'M';
		}
		if (map[player_y - 1][player_x] == '1' && map[player_y][player_x + 1] != '1')
		{
			player_x--;
			map[player_y][player_x] = 'M';
		}
		while (map[player_y][player_x - 1] != '1')
		{
			player_x--;
			map[player_y][player_x] = 'M';
		}
		while (map[player_y][player_x + 1] != '1')
		{
			player_x++;
			map[player_y][player_x] = 'M';
		}

		if (player_y == object_cord[i].y && player_x == object_cord[i].x)
			i++;

			}
	if (x, y == P)
		return 1
	x, y = 1
	if x + 1 | y == 1
		rec ( x+1 y, map)
	if x + -1 | y == 1
	if x  | y +1 == 1
	if x | y -1 == 1*/