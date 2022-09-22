/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:05:20 by misimon           #+#    #+#             */
/*   Updated: 2022/04/27 17:29:39 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;
	size_t	i;

	i = 0;
	s = b;
	while (i < len)
		s[i++] = (unsigned char)c;
	return (b);
}
