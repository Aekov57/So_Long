/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:58:29 by misimon           #+#    #+#             */
/*   Updated: 2022/09/28 18:02:43 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	format_verif(char *file)
{
	size_t	i;
	char	*format;

	i = ft_strlen(file) - 1;
	while (file[i] != '.')
		i--;
	format = ft_substr(file, i, 5);
	if (!format)
		return (error("error at format verif !") + 1);
	if (ft_strcmp(format, ".ber") == 0)
		return (str_success(format, "Format = .ber !"));
	return (0);
}

void	check_symbol(t_map map, char *str, t_var *mlx)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == WALL || str[i] == FLOOR || str[i] == EXIT \
		|| str[i] == COLLECT || str[i] == PLAYER || str[i] == '\n')
			i++;
		else
		{
			close(map.file);
			exit(error_esc("Wrong character in map !", mlx));
		}
	}
}

t_map	init_map(t_map map, t_var *mlx, char *av)
{
	map.size.y = 0;
	map.file = check_open(map.file, mlx, av);
	map.column = get_next_line(map.file);
	if (!map.column)
		exit(error_esc("Map file is empty !", mlx));
	map.save = "\0";
	while (map.column)
	{
		if (map.column[0] == '\n')
			exit(error_esc("Empty line detected !", mlx));
		map.save = ft_strjoin(map.save, map.column);
		map.column = get_next_line(map.file);
		map.size.y++;
	}
	check_symbol(map, map.save, mlx);
	map.data = ft_split(map.save, '\n');
	map.size.x = check_size(map, mlx);
	close(map.file);
	return (map);
}