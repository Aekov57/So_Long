/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:53:20 by misimon           #+#    #+#             */
/*   Updated: 2022/06/29 15:04:03 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int closemlx(int keycode ,t_var sol)
{
	(void) keycode;
	(void) sol;
	exit(0);
}

static t_var test_visual(t_var solng)
{
	t_var sovar = solng;
	void		*walltexture;
	void		*floortexture;
	int			width;
	int			height;
	int xcount;
	int ycount;

	xcount = 0;
	ycount = 0;
	mlx_new_image(sovar.mlx, sovar.mapsize_x, sovar.mapsize_y);
	walltexture = mlx_png_file_to_image(sovar.mlx, "wall.png", &width, &height);
	floortexture = mlx_png_file_to_image(sovar.mlx, "grass.png", &width, &height);
	while (sovar.map[ycount])
	{
		while (sovar.map[ycount][xcount])
		{
			if(sovar.map[ycount][xcount] == '1')
			{
				mlx_destroy_image(sovar.mlx, walltexture);
				mlx_put_image_to_window (sovar.mlx, sovar.win, walltexture, 32*xcount, 32*ycount);
			}
			if(sovar.map[ycount][xcount] == '0')
			{
				mlx_destroy_image(sovar.mlx, walltexture);
				mlx_put_image_to_window (sovar.mlx, sovar.win, floortexture, 32*xcount, 32*ycount);
			}
			xcount++;
		}
		xcount = 0;
		ycount++;
	}
	mlx_destroy_image(sovar.mlx, walltexture);
	mlx_destroy_image(sovar.mlx, floortexture);
	return(sovar);
}

int main(int argc, char **argv)
{
	t_var	sol;
	int		i;

	i = 0;
	if(argc != 2)
	{
		ft_printf("Invalid argument !\n");
		return(-1);
	}
	sol = read_map(argv[1]);
	if(sol.map_error == -1)
		return(-1);
	sol.mlx = mlx_init();
	sol.win = mlx_new_window(sol.mlx, (sol.mapsize_x*32), sol.mapsize_y*32, "SO_LONG");
	sol = test_visual(sol);
	mlx_hook(sol.win, ON_DESTROY, 0, closemlx, &sol);

	mlx_loop(sol.mlx);
	return(0);
}