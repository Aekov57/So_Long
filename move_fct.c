/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:44:46 by misimon           #+#    #+#             */
/*   Updated: 2022/09/26 23:01:01 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_var *mlx, int *step)
{
	if (mlx->map.data[mlx->player.y - 1][mlx->player.x] != 'E')
	{
		if (mlx->map.data[mlx->player.y][mlx->player.x] != 'E')
			mlx->map.data[mlx->player.y][mlx->player.x] = '0';
		if (mlx->map.data[mlx->player.y - 1][mlx->player.x] == 'C')
		{
			mlx->object.n_collect--;
			mlx->map.data[mlx->player.y - 1][mlx->player.x] = '0';
			place_texture(mlx);
		}
		mlx->map.data[--mlx->player.y][mlx->player.x] = 'P';
	}
	else if (mlx->map.data[mlx->player.y - 1][mlx->player.x] == 'E')
	{
		mlx->map.data[mlx->player.y][mlx->player.x] = '0';
		mlx->map.data[--mlx->player.y][mlx->player.x] = 'E';
	}
	mlx->t_player.img->instances[0].y -= 64;
	(*step)++;
}

void	down(t_var *mlx, int *step)
{
	if (mlx->map.data[mlx->player.y + 1][mlx->player.x] != 'E')
	{
		if (mlx->map.data[mlx->player.y][mlx->player.x] != 'E')
			mlx->map.data[mlx->player.y][mlx->player.x] = '0';
		if (mlx->map.data[mlx->player.y + 1][mlx->player.x] == 'C')
		{
			mlx->object.n_collect--;
			mlx->map.data[mlx->player.y + 1][mlx->player.x] = '0';
			place_texture(mlx);
		}
		mlx->map.data[++mlx->player.y][mlx->player.x] = 'P';
	}
	else if (mlx->map.data[mlx->player.y + 1][mlx->player.x] == 'E')
	{
		mlx->map.data[mlx->player.y][mlx->player.x] = '0';
		mlx->map.data[++mlx->player.y][mlx->player.x] = 'E';
	}
	mlx->t_player.img->instances[0].y += 64;
	(*step)++;
}

void	right(t_var *mlx, int *step)
{
	if (mlx->map.data[mlx->player.y][mlx->player.x + 1] != 'E')
	{
		if (mlx->map.data[mlx->player.y][mlx->player.x] != 'E')
			mlx->map.data[mlx->player.y][mlx->player.x] = '0';
		if (mlx->map.data[mlx->player.y][mlx->player.x + 1] == 'C')
		{
			mlx->object.n_collect--;
			mlx->map.data[mlx->player.y][mlx->player.x + 1] = '0';
			place_texture(mlx);
		}
		mlx->map.data[mlx->player.y][++mlx->player.x] = 'P';
	}
	else if (mlx->map.data[mlx->player.y][mlx->player.x + 1] == 'E')
	{
		mlx->map.data[mlx->player.y][mlx->player.x] = '0';
		mlx->map.data[mlx->player.y][++mlx->player.x] = 'E';
	}
	mlx->t_player.img->instances[0].x += 64;
	(*step)++;
}

void	left(t_var *mlx, int *step)
{
	if (mlx->map.data[mlx->player.y][mlx->player.x - 1] != 'E')
	{
		if (mlx->map.data[mlx->player.y][mlx->player.x] != 'E')
			mlx->map.data[mlx->player.y][mlx->player.x] = '0';
		if (mlx->map.data[mlx->player.y][mlx->player.x - 1] == 'C')
		{
			mlx->object.n_collect--;
			mlx->map.data[mlx->player.y][mlx->player.x - 1] = '0';
			place_texture(mlx);
		}
		mlx->map.data[mlx->player.y][--mlx->player.x] = 'P';
	}
	else if (mlx->map.data[mlx->player.y][mlx->player.x - 1] == 'E')
	{
		mlx->map.data[mlx->player.y][mlx->player.x] = '0';
		mlx->map.data[mlx->player.y][--mlx->player.x] = 'E';
	}
	mlx->t_player.img->instances[0].x -= 64;
	(*step)++;
}

void	print_move(int step, t_var *mlx)
{
	int	i;

	i = -1;
	ft_printf("\033[2J\r\033[H\r\033[2K\033[1A\r\033[2K\033[1A\r");
	while (mlx->map.data[++i])
		ft_printf("\033[2K\033[1A\r");
	i = -1;
	while (mlx->map.data[++i])
		ft_printf("%s\n", mlx->map.data[i]);
	ft_printf("Step [%d]\nObject [%d]\n", step, mlx->object.n_collect);
}
