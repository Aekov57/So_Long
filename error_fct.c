/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:39:47 by misimon           #+#    #+#             */
/*   Updated: 2022/10/03 15:14:38 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *str)
{
	ft_printf("\033[0;31mERROR : %s\033[0m\n", str);
	return (0);
}

int	error_esc(char *str, t_var *mlx)
{
	free(mlx);
	ft_printf("\033[0;31mERROR : %s\033[0m\n", str);
	return (0);
}
