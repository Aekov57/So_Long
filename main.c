/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:58:33 by misimon           #+#    #+#             */
/*   Updated: 2022/09/22 19:38:58 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_used(mlx_key_data_t keydata, t_var *mlx)
{
	static int i = 0;

	if (keydata.key == MLX_KEY_ESCAPE)
		exit(esc_success(mlx, "Escape pressed !"));
	if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
	{
		if (mlx->map.data[mlx->player.y - 1][mlx->player.x] != '1')
		{
			if (mlx->map.data[mlx->player.y - 1][mlx->player.x] == 'C')
			{
				mlx->object.n_collect--;
				mlx->map.data[mlx->player.y - 1][mlx->player.x] = '0';
				place_texture(mlx);
			}
			if (mlx->map.data[mlx->player.y - 1][mlx->player.x] == 'E' && mlx->object.n_collect == 0)
				exit (esc_success(mlx, "Game closed !"));
			mlx->map.data[--mlx->player.y][mlx->player.x] = 'P';
			mlx->map.data[mlx->player.y + 1][mlx->player.x] = '0';
			mlx->t_player.img->instances[0].y -= 64;
			ft_printf("\n%s [%d] ", mlx->map.data[mlx->player.y], mlx->object.n_collect);
			ft_printf("UP -> %d\n", ++i);
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
	{
		if(mlx->map.data[mlx->player.y + 1][mlx->player.x] != '1')
		{
			if (mlx->map.data[mlx->player.y + 1][mlx->player.x] == 'C')
			{
				mlx->object.n_collect--;
				mlx->map.data[mlx->player.y + 1][mlx->player.x] = '0';
				place_texture(mlx);
			}
			if (mlx->map.data[mlx->player.y + 1][mlx->player.x] == 'E' && mlx->object.n_collect == 0)
				exit (esc_success(mlx, "Game closed !"));
			mlx->map.data[++mlx->player.y][mlx->player.x] = 'P';
			mlx->map.data[mlx->player.y - 1][mlx->player.x] = '0';
			mlx->t_player.img->instances[0].y += 64;
			ft_printf("\n%s [%d] ", mlx->map.data[mlx->player.y], mlx->object.n_collect);
			ft_printf("DOWN -> %d\n", ++i);
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
	{
		if(mlx->map.data[mlx->player.y][mlx->player.x + 1] != '1')
		{
			if (mlx->map.data[mlx->player.y][mlx->player.x + 1] == 'C')
			{
				mlx->object.n_collect--;
				mlx->map.data[mlx->player.y][mlx->player.x + 1] = '0';
				place_texture(mlx);
			}
			if (mlx->map.data[mlx->player.y][mlx->player.x + 1] == 'E' && mlx->object.n_collect == 0)
				exit (esc_success(mlx, "Game closed !"));
			mlx->map.data[mlx->player.y][++mlx->player.x] = 'P';
			mlx->map.data[mlx->player.y][mlx->player.x - 1] = '0';
			mlx->t_player.img->instances[0].x += 64;
			ft_printf("\n%s [%d] ", mlx->map.data[mlx->player.y], mlx->object.n_collect);
			ft_printf("RIGHT -> %d\n", ++i);
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
	{
		if(mlx->map.data[mlx->player.y][mlx->player.x - 1] != '1')
		{
			if (mlx->map.data[mlx->player.y][mlx->player.x - 1] == 'C')
			{
				mlx->object.n_collect--;
				mlx->map.data[mlx->player.y][mlx->player.x - 1] = '0';
				place_texture(mlx);
			}
			if (mlx->map.data[mlx->player.y][mlx->player.x - 1] == 'E' && mlx->object.n_collect == 0)
				exit (esc_success(mlx, "Game closed !"));
			mlx->map.data[mlx->player.y][--mlx->player.x] = 'P';
			mlx->map.data[mlx->player.y][mlx->player.x + 1] = '0';
			mlx->t_player.img->instances[0].x -= 64;
			ft_printf("\n%s [%d] ", mlx->map.data[mlx->player.y], mlx->object.n_collect);
			ft_printf("LEFT -> %d\n", ++i);
		}
	}
}

void	key_funct(mlx_key_data_t keydata, void *param)
{
	key_used(keydata, (t_var *)param);
}

int	main(int ac, char **av)
{
	t_var	*mlx;

	mlx = malloc(sizeof(t_var));
	if (ac != 2)
		return (error_esc("Argument problem !", mlx));
	mlx->map = init_map(mlx->map, mlx, av[1]);
	mlx->data = mlx_init(mlx->map.size.x * 64, mlx->map.size.y * 64,
			"so_long", 0);
	if (check_wall(mlx->map, mlx) != 1)
		exit (error_esc("Map incorrect !", mlx));
	place_texture(mlx);
	//mlx_loop_hook(mlx->data, &hook, (void *)mlx);
	mlx_key_hook(mlx->data, key_funct, (void *)mlx);
	mlx_loop(mlx->data);
	mlx_terminate(mlx->data);
	return (esc_success(mlx, "Game closed !"));
}
