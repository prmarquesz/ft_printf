/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:19:58 by proberto          #+#    #+#             */
/*   Updated: 2021/07/23 23:30:37 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_width(t_spec *spec);
static void	write_prec(t_spec *spec);

void	ft_write_ptr(t_spec *spec)
{
	if ((spec->flag.status == ON && spec->flag.token == ' ')
		|| (spec->flag.status == OFF))
		write_width(spec);
	spec->count += ft_putstr_fd("0x", 1);
	if (spec->flag.status == ON && spec->flag.token == '0')
		write_width(spec);
	write_prec(spec);
	if (spec->data.value.pvalue)
		spec->count += ft_putlx_fd(spec->data.value.pvalue, 1);
	if ((spec->flag.status == ON && spec->flag.token == '-')
		|| spec->flag.token == '0')
		write_width(spec);
}

static void	write_width(t_spec *spec)
{
	while ((spec->width.value > spec->precision.value + 2)
		&& (spec->width.value > spec->data.length.digits + 2))
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
