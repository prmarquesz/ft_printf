/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 07:08:39 by proberto          #+#    #+#             */
/*   Updated: 2021/06/03 17:12:01 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoc(char *nbr, int n, int digits);

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr[13];

	if (n == 0 || (n >= 0 && n <= 9))
		ft_putchar_fd(n + '0', fd);
	else
		ft_putstr_fd(itoc(nbr, n, 2), fd);
}

static char	*itoc(char *nbr, int n, int digits)
{
	long long	n_aux;

	if (n < 0)
	{
		nbr[0] = '-';
		n_aux = (long long) n * -1;
	}
	else
		n_aux = (long long) n;
	n = n / 10;
	while (n)
	{
		n /= 10;
		digits++;
	}
	nbr[digits] = '\0';
	while (digits > 1)
	{
		nbr[--digits] = (n_aux % 10) + '0';
		n_aux /= 10;
	}
	if (nbr[0] == '-')
		return (nbr);
	else
		return (&nbr[1]);
}
