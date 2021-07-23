/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlx_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 03:00:16 by proberto          #+#    #+#             */
/*   Updated: 2021/07/22 21:19:35 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*lxtoc(char *nbr, uintptr_t n, int digits);

int	ft_putlx_fd(uintptr_t n, int fd)
{
	char	nbr[17];

	if (n == 0 || (n > 0 && n <= 9))
		return (ft_putchar_fd(n + '0', fd));
	else
		return (ft_putstr_fd(lxtoc(nbr, n, 0), fd));
}

static char	*lxtoc(char *nbr, uintptr_t n, int digits)
{
	uintptr_t	n_aux;
	int			hex;

	n_aux = n;
	while (n)
	{
		n /= 16;
		digits++;
	}
	nbr[digits] = '\0';
	while (digits)
	{
		hex = (n_aux % 16) + '0';
		if (hex > '9')
			hex += 39;
		nbr[--digits] = hex;
		n_aux /= 16;
	}
	return (nbr);
}
