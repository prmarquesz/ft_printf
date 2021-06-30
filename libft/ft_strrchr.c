/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:11:53 by proberto          #+#    #+#             */
/*   Updated: 2021/06/07 16:36:07 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*s_aux;
	unsigned char	find;
	size_t			i;

	s_aux = (unsigned char *)s;
	find = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s_aux[i] == find)
			return ((char *)s_aux + i);
		i--;
	}
	if (s_aux[i] == find)
		return ((char *)s_aux);
	return (NULL);
}
