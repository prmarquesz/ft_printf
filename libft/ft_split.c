/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:03:50 by proberto          #+#    #+#             */
/*   Updated: 2021/06/06 03:37:58 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**str_populate(char **str, char *s, size_t size, char c);
static int		get_index(char *s, char c, int offset);
static int		get_len(char *s, char c, int opt);
static void		*mem_clean(char **str, size_t stop);

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**str;
	char	*s_aux;
	char	delimiter[2];

	if (!s)
		return (NULL);
	delimiter[0] = c;
	delimiter[1] = '\0';
	s_aux = ft_strtrim(s, delimiter);
	if (!s_aux)
		return (NULL);
	if (*s_aux == '\0')
		size = 0;
	else
		size = get_len(s_aux, c, 1);
	str = (char **)malloc((size + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str_populate(str, s_aux, size, c);
	free(s_aux);
	return (str);
}

static char	**str_populate(char **str, char *s, size_t size, char c)
{
	size_t	i;
	size_t	offset;
	size_t	len;

	i = 0;
	offset = i;
	len = i;
	while (i < size)
	{
		offset = get_index(s, c, offset);
		len = get_len(&s[offset], c, 2);
		str[i] = (char *) ft_substr(s, offset, len);
		if (!str[i])
			return (mem_clean(str, size - 1));
		offset += len;
		i++;
	}
	str[i] = NULL;
	return (str);
}

static int	get_index(char *s, char c, int offset)
{
	while (*(s + offset) == c)
		offset++;
	return (offset);
}

static int	get_len(char *s, char c, int opt)
{
	size_t	i;

	if (opt == 1)
	{
		i = 1;
		while (*s)
		{
			if (*s == c && *(s + 1) != c)
				i++;
			s++;
		}
	}
	else
	{
		i = 0;
		while (*s && *s != c)
		{
			i++;
			s++;
		}
	}
	return (i);
}

static void	*mem_clean(char **str, size_t stop)
{
	size_t	i;

	i = 0;
	while (i < stop)
		free(str[i]);
	free(str);
	return (NULL);
}
