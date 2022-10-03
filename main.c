/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:58:33 by misimon           #+#    #+#             */
/*   Updated: 2022/10/03 13:29:31 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_funct(mlx_key_data_t keydata, void *param)
{
	t_var		*mlx;
	static int	step;

	mlx = (t_var *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(mlx->data);
		exit(esc_success(mlx, "Escape pressed !"));
	}
	if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
		if (mlx->map.data[mlx->player.y - 1][mlx->player.x] != '1')
			up(mlx, &step);
	if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
		if (mlx->map.data[mlx->player.y + 1][mlx->player.x] != '1')
			down(mlx, &step);
	if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
		if (mlx->map.data[mlx->player.y][mlx->player.x + 1] != '1')
			right(mlx, &step);
	if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
		if (mlx->map.data[mlx->player.y][mlx->player.x - 1] != '1')
			left(mlx, &step);
	if (mlx->map.data[mlx->player.y][mlx->player.x] == 'E'
			&& mlx->object.n_collect == 0)
		exit (esc_success(mlx, "Game closed !"));
	print_move(step, mlx);
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
	check_access(mlx);
	place_texture(mlx);
	mlx_key_hook(mlx->data, key_funct, (void *)mlx);
	mlx_loop(mlx->data);
	mlx_terminate(mlx->data);
	free_map(mlx->map.data);
	return (esc_success(mlx, "Game closed !"));
}
