/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:49:16 by misimon           #+#    #+#             */
/*   Updated: 2022/06/28 21:00:27 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>

enum nombre
{
	ON_KEYDOWN = 2,
	ON_KEYUP,
	ON_MOUSEDOWN,
	ON_MOUSEUP,
	ON_MOUSEMOVE,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	SIZE_X = 1280,
	SIZE_Y = 720
};

typedef struct s_var
{
	void *mlx;
	void *win;
	char **map;
	int map_fd;
	int map_x;
	int map_y;
	int map_error;

} t_var;

t_var read_map(char *file);

#endif
