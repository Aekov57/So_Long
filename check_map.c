/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:40:13 by misimon           #+#    #+#             */
/*   Updated: 2022/09/20 17:50:41 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_open(int fd, t_var *mlx, char *av)
{
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit (error_esc("File doesn't exist !", mlx));
	if (format_verif(av) != 1)
	{
		close(mlx->map.file);
		exit (error_esc("Invalid format !", mlx));
	}
	return (fd);
}

size_t	check_size(t_map map, t_var *mlx)
{
	size_t	actual;
	size_t	y;
	size_t	last;

	y = 0;
	actual = line_strlen(map.data[y]);
	while (map.data[y])
	{
		last = actual;
		actual = line_strlen(map.data[y]);
		if (last != actual)
		{
			ft_printf("\nActual = %d, Last = %d\n", actual, last);
			exit(error_esc("Size is incorrect !", mlx));
		}
		++y;
	}
	return (actual);
}

int if_wall(int x, int y, t_map map)
{
	if(map.data[0][x] != WALL)
		return(error("External wall is not complete !"));
	if(map.data[y][0] != WALL)
		return(error("External wall is not complete !"));
	if(map.data[y][ft_strlen(map.data[y]) - 1] != WALL)
		return(error("External wall is not complete !"));
	if(!map.data[y + 1] && map.data[y][x] != WALL)
		return(error("External wall is not complete !"));
	return(1);
}

t_var *count_object(int x, int y, t_var *mlx)
{
	if(mlx->map.data[y][x] == COLLECT)
		mlx->object.n_collect++;
	if(mlx->map.data[y][x] == EXIT)
		mlx->object.n_exit++;
	if(mlx->map.data[y][x] == PLAYER)
	{
		mlx->player.x = x;
		mlx->player.y = y;
		mlx->object.n_player++;
	}
	return(mlx);
}

int check_wall(t_map map, t_var *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx->object.n_collect = 0;
	mlx->object.n_exit = 0;
	mlx->object.n_player = 0;
	mlx->player.x = 0;
	mlx->player.y = 0;
	while(map.data[y])
	{
		while (map.data[y][x])
		{
			if(!if_wall(x, y, map))
				return(0);
			mlx = count_object(x, y, mlx);
			x++;
		}
		x = 0;
		y++;
	}
	if(mlx->object.n_collect <= 0)
		return(error("Less than 1 collectible !"));
	if(mlx->object.n_exit != 1 || mlx->object.n_player != 1)
		return(error("More or less than 1 exit or player !"));
	return(1);
}