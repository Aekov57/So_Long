/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:04:06 by misimon           #+#    #+#             */
/*   Updated: 2022/09/19 23:24:02 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*chr;
	size_t	i;
	size_t	size_str;

	i = 0;
	if (!s)
		return (NULL);
	size_str = ft_strlen(s);
	if (start > size_str)
	{
		chr = malloc(sizeof(char));
		chr[0] = 0;
		return (chr);
	}
	chr = malloc(sizeof(*s) * ((size_str - start) + 1));
	if (!chr)
		return (NULL);
	while (i < len && s[start] != 0)
		chr[i++] = s[start++];
	chr[i] = '\0';
	return (chr);
}
