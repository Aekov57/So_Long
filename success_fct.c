/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:40:44 by misimon           #+#    #+#             */
/*   Updated: 2022/10/03 15:15:19 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_success(t_var *mlx, char *str)
{
	free(mlx);
	ft_printf("\033[0;32mSUCCESS : %s\033[0m\n", str);
	return (1);
}

int	str_success(char *str, char *msg)
{
	free(str);
	ft_printf("\033[0;32mSUCCESS : %s\033[0m\n", msg);
	return (1);
}
