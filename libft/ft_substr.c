/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:03:30 by proberto          #+#    #+#             */
/*   Updated: 2021/06/07 19:56:20 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	len_s;
	char	*substr;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		size = 1;
	else if (start + len > len_s)
		size = len_s - start + 1;
	else
		size = len + 1;
	substr = (char *) malloc(size * sizeof(char));
	if (!substr)
		return (NULL);
	size = ft_strlcpy(substr, &s[start], size);
	return (substr);
}
