/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:16:47 by proberto          #+#    #+#             */
/*   Updated: 2021/07/23 20:30:41 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_width(t_spec *spec);
static void	write_prec(t_spec *spec);

void	ft_write_uint(t_spec *spec)
{
	if ((spec->flag.status == ON && spec->flag.token == '0')
			|| (spec->flag.status == OFF))
		write_width(spec);
	write_prec(spec);
	if (spec->data.value.uvalue)
	{
		if (spec->data.token == 'u')
			spec->count += ft_putpnbr_fd(spec->data.value.uvalue, 1);
		else
			spec->count += ft_putx_fd(spec->data.value.uvalue,
				spec->data.token, 1);
	}
	if (spec->flag.status == ON && spec->flag.token == '-')
		write_width(spec);
}

static void	write_width(t_spec *spec)
{
	while ((spec->width.value > spec->precision.value)
		&& (spec->width.value > spec->data.length.digits))
	{
		spec->count += ft_putchar_fd(spec->width.fill, 1);
		spec->width.value--;
	}
}

static void	write_prec(t_spec *spec)
{
	while (spec->data.length.digits < spec->precision.value)
	{
		spec->count += ft_putchar_fd(spec->precision.fill, 1);
		spec->data.length.digits++;
	}
}
