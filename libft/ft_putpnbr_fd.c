/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 02:44:39 by proberto          #+#    #+#             */
/*   Updated: 2021/07/06 13:51:51 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*utoc(char *nbr, unsigned int n, int digits);

int	ft_putpnbr_fd(unsigned int n, int fd)
{
	char	nbr[11];

	if (n == 0 || (n > 0 && n <= 9))
		return (ft_putchar_fd(n + '0', fd));
	else
		return (ft_putstr_fd(utoc(nbr, n, 0), fd));
}

static char	*utoc(char *nbr, unsigned int n, int digits)
{
	unsigned int	n_aux;

	n_aux = n;
	while (n)
	{
		n /= 10;
		digits++;
	}
	nbr[digits] = '\0';
	while (digits)
	{
		nbr[--digits] = (n_aux % 10) + '0';
		n_aux /= 10;
	}
	return (nbr);
}
