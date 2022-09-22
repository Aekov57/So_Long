/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:03:22 by misimon           #+#    #+#             */
/*   Updated: 2022/09/22 19:48:09 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture exec_texture(t_var *mlx, int x, int y, t_texture txt)
{
	txt.xpm = mlx_load_xpm42(txt.path);
	if(!txt.xpm)
		exit(error_esc("Can't load png !", mlx));
	if(txt.xpm->texture.height != 64 || txt.xpm->texture.width != 64)
		exit(error_esc("texture size is not 64x64 !", mlx));
	txt.img = mlx_texture_to_image(mlx->data, &txt.xpm->texture);
	if (mlx_image_to_window(mlx->data, txt.img, 64*x, 64*y) < 0)
		exit(error("Texture failed !"));
	return(txt);
}

void	if_texture(int x, int y, t_var *mlx)
{
	if (mlx->map.data[y][x] != WALL)
	{
		mlx->floor.path = "assets/floor.xpm42";
		mlx->floor = exec_texture(mlx, x, y, mlx->floor);
	}
	if (mlx->map.data[y][x] == WALL)
	{
		mlx->wall.path = "assets/wall.xpm42";
		mlx->wall = exec_texture(mlx, x, y, mlx->wall);
	}
	if (mlx->map.data[y][x] == COLLECT)
	{
		mlx->collect.path = "assets/collect.xpm42";
		mlx->collect = exec_texture(mlx, x, y, mlx->collect);
	}
	if (mlx->map.data[y][x] == EXIT)
	{
		mlx->close.path = "assets/exit.xpm42";
		mlx->close = exec_texture(mlx, x, y, mlx->close);
	}
	if (mlx->map.data[y][x] == EXIT && mlx->object.n_collect == 0)
	{
		mlx->open.path = "assets/exit_open.xpm42";
		mlx->open = exec_texture(mlx, x, y, mlx->open);
	}
}

void place_texture(t_var *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(mlx->map.data[y])
	{
		while (mlx->map.data[y][x])
		{
			if_texture(x, y, mlx);
			x++;
		}
		x = 0;
		y++;
	}
	mlx->t_player.path = "assets/player.xpm42";
	mlx->t_player = exec_texture(mlx, mlx->player.x, mlx->player.y, mlx->t_player);
}
