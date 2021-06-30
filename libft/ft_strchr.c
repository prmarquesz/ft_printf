/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:52:47 by proberto          #+#    #+#             */
/*   Updated: 2021/06/07 16:20:27 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_aux;
	unsigned char	find;

	s_aux = (unsigned char *)s;
	find = (unsigned char)c;
	while (*s_aux)
	{
		if (*s_aux == find)
			return ((char *)s_aux);
		s_aux++;
	}
	if (*s_aux == find)
		return ((char *)s_aux);
	return (NULL);
}
