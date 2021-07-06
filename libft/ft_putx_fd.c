/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:31:22 by proberto          #+#    #+#             */
/*   Updated: 2021/07/06 13:58:57 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*xtoc_lower(char *nbr, unsigned int n, int digits);
static char	*xtoc_upper(char *nbr, unsigned int n, int digits);

int	ft_putx_fd(unsigned int n, char c, int fd)
{
	char	nbr[13];

	if (n == 0 || (n > 0 && n <= 9))
		return (ft_putchar_fd(n + '0', fd));
	else if (c == 'x')
		return (ft_putstr_fd(xtoc_lower(nbr, n, 0), fd));
	else
		return (ft_putstr_fd(xtoc_upper(nbr, n, 0), fd));
}

static char	*xtoc_lower(char *nbr, unsigned int n, int digits)
{
	unsigned int	n_aux;
	int				hex;

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

static char	*xtoc_upper(char *nbr, unsigned int n, int digits)
{
	unsigned int	n_aux;
	int				hex;

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
			hex += 7;
		nbr[--digits] = hex;
		n_aux /= 16;
	}
	return (nbr);
}
