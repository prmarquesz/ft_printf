/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 06:49:11 by proberto          #+#    #+#             */
/*   Updated: 2021/06/03 20:37:03 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_populate(char *str, int len, int n);
static int	num_chars(int n);

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	if (n == 0)
		len = 2;
	else
		len = num_chars(n) + 1;
	nbr = (char *) malloc(len * sizeof(char));
	if (!nbr)
		return (NULL);
	str_populate(nbr, len, n);
	return (nbr);
}

static int	num_chars(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*str_populate(char *str, int len, int n)
{
	int	sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len--;
	str[len] = '\0';
	while (len--)
	{
		if (sign == -1 && len == 0)
		{
			str[len] = '-';
			break ;
		}
		str[len] = ((n % 10) * sign) + '0';
		n /= 10;
	}
	return (str);
}
