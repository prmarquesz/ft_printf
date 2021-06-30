/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:57:29 by proberto          #+#    #+#             */
/*   Updated: 2021/06/07 23:17:23 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	offset;
	size_t	end;
	char	*strtrim;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	offset = 0;
	len = 0;
	while (offset < end && ft_strchr(set, s1[offset]))
		offset++;
	while (end > offset && ft_strrchr(set, s1[end - 1]))
		end--;
	len = (end - offset) + 1;
	strtrim = (char *) malloc(len * sizeof(char));
	if (!strtrim)
		return (NULL);
	ft_strlcpy(strtrim, &s1[offset], len);
	return (strtrim);
}
