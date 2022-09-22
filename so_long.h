/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:58:56 by misimon           #+#    #+#             */
/*   Updated: 2022/09/22 17:04:06 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/include/MLX42/MLX42.h"

enum e_map_info
{
	FLOOR = '0',
	WALL = '1',
	COLLECT = 'C',
	PLAYER = 'P',
	EXIT = 'E',
};

typedef struct s_player
{
	int x;
	int y;
}	t_player;

typedef struct s_object
{
	int n_collect;
	int n_exit;
	int n_player;
} t_object;

typedef struct s_texture
{
	char *path;
	xpm_t *xpm;
	mlx_image_t *img;
} t_texture;


typedef struct s_size
{
	int x;
	int y;
} t_size;

typedef struct s_map
{
	t_size	size;
	int		file;
	char	*save;
	char	**data;
	char	*column;
} t_map;

typedef struct s_var
{
	void	*data;
	t_map	map;
	t_object object;
	t_player player;
	t_texture floor;
	t_texture wall;
	t_texture collect;
	t_texture t_player;
	t_texture close;
	t_texture open;
} t_var;

int	error(char *str);
int	esc_success(t_var *mlx, char *str);
int	check_open(int fd, t_var *mlx, char *av);
int	str_success(char *str, char *msg);
size_t	line_strlen(char *c);
int	ft_strcmp(const char *s1, const char *s2);
int	error_esc(char *str, t_var *mlx);
t_map	init_map(t_map map, t_var *mlx, char *av);
size_t	check_size(t_map map, t_var *mlx);
void	check_symbol(t_map map, char *str, t_var *mlx);
int	format_verif(char *file);
int check_wall(t_map map, t_var *mlx);
void place_texture(t_var *mlx);
t_texture exec_texture(t_var *mlx, int x, int y, t_texture txt);

#endif