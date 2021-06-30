/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:33:39 by proberto          #+#    #+#             */
/*   Updated: 2021/06/07 13:26:59 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	offset;
	size_t	len;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *) malloc((len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	offset = 0;
	while (*s1)
		s3[offset++] = *s1++;
	while (*s2)
		s3[offset++] = *s2++;
	s3[offset] = '\0';
	return (s3);
}
