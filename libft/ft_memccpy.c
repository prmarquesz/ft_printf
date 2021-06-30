/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 00:02:59 by proberto          #+#    #+#             */
/*   Updated: 2021/05/29 00:52:32 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	i = 0;
	ptr_src = (unsigned char *) src;
	ptr_dst = dst;
	while (i < n)
	{
		ptr_dst[i] = (unsigned char) ptr_src[i];
		if (ptr_src[i] == (unsigned char) c)
			return ((unsigned char *) dst + i + 1);
		i++;
	}
	return (NULL);
}
