/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:11:22 by misimon           #+#    #+#             */
/*   Updated: 2022/09/22 16:40:01 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	int		verif;
	char	*str;
	char	buffer[2];

	verif = read(fd, buffer, BUFFER_SIZE / BUFFER_SIZE);
	if (fd <= -1 || fd > 1023 || verif <= 0)
		return (NULL);
	str = malloc(1);
	str[0] = '\0';
	while (verif == 1 && buffer[0] != '\n')
	{
		str = ft_strexpand(str, buffer);
		verif = read(fd, buffer, 1);
	}
	if (buffer[0] == '\n')
		str = ft_strjoin(str, "\n");
	return (str);
}
