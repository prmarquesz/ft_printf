/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 11:59:52 by proberto          #+#    #+#             */
/*   Updated: 2021/06/06 02:55:29 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_aux;
	unsigned char	*end_s;

	s_aux = (unsigned char *) s;
	end_s = (unsigned char *) s + n;
	while (s_aux < end_s)
	{
		if (*s_aux == (unsigned char) c)
			return (s_aux);
		s_aux++;
	}
	return (NULL);
}
