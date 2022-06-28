/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:20:04 by misimon           #+#    #+#             */
/*   Updated: 2022/06/28 20:27:15 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int map_v_len(char *file)
{
	char	*line;
	int		l_count;
	int		op_file;

	l_count = 0;
	op_file = open(file, O_RDONLY);
	if (op_file < 0)
	{
		close(op_file);
		ft_printf("file doesn't exist !\n");
		return (-1);
	}
	while ((line = get_next_line(op_file)))
		l_count++;
	free(line);
	close(op_file);
	printf("%d\n", l_count);
	return (l_count);

}
/*
static int verif_map(char **map)
{
	int x = 0;
	int y = 0;
	while (map[y])
	{
		while (map[y][x+1])
		{
			if(map[0][x] != '1' || (!map[y+1] && map[y][x] != '1'))
				return (-1);
			++x;
		}
	x = 0;
	y++;
	}
	return(0);
}*/

t_var read_map(char *file)
{
	t_var map_var;
	int vertical_len;
	int map_count;

	map_count = 0;
	vertical_len = map_v_len(file);
	if (vertical_len == -1)
	{
		map_var.map_error = -1;
		return(map_var);
	}
	map_var.map = calloc(vertical_len, sizeof(char *));
	map_var.map_fd = open(file, O_RDONLY);
	while ((map_var.map[map_count] = get_next_line(map_var.map_fd)))
		ft_printf("%s", map_var.map[map_count++]);
	map_var.map_x = ft_strlen(map_var.map[0]);
	map_var.map_y = map_count;
	close(map_var.map_fd);
	return(map_var);
}

/*map_var.map_error = verif_map(map_var.map);
	if (map_var.map_error == -1)
	{
		ft_printf("\nmap error !");
		return(map_var);
	}*/