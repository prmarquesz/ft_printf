/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:22:01 by proberto          #+#    #+#             */
/*   Updated: 2021/07/23 16:06:04 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_char(t_spec *spec);
static void	write_str(t_spec *spec);
static void	write_width(t_spec *spec);
static void	write_prec(t_spec *spec);

void	ft_write_char(t_spec *spec)
{
	if (spec->data.type == CHR)
		write_char(spec);
	else
		write_str(spec);
}

static void	write_char(t_spec *spec)
{
	if (spec->flag.status == ON && spec->flag.token == '-')
	{
		spec->count += ft_putchar_fd(spec->data.value.value, 1);
		while (spec->width.value-- > spec->data.length.len)
			spec->count += ft_putchar_fd(spec->width.fill, 1);
	}
	else
	{
		while (spec->width.value-- > spec->data.length.len)
			spec->count += ft_putchar_fd(spec->width.fill, 1);
		spec->count += ft_putchar_fd(spec->data.value.value, 1);
	}
}

static void	write_str(t_spec *spec)
{
	if (spec->flag.status == ON && spec->flag.token == '-')
	{
		write_prec(spec);
		write_width(spec);
	}
	else
	{
		write_width(spec);
		write_prec(spec);
	}
}

static void	write_width(t_spec *spec)
{
	if ((spec->precision.value >= spec->data.length.len)
		|| (spec->precision.status == OFF))
		while (spec->width.value-- > spec->data.length.len)
			spec->count += ft_putchar_fd(spec->width.fill, 1);
	else
		while (spec->width.value-- > spec->precision.value)
			spec->count += ft_putchar_fd(spec->width.fill, 1);
}

static void	write_prec(t_spec *spec)
{
	if ((spec->precision.value >= spec->data.length.len)
			|| (spec->precision.status == OFF))
	{
		spec->count += ft_putstr_fd(spec->data.value.svalue, 1);
		spec->precision.value = spec->data.length.len;
	}
	else
		spec->count += write(1, spec->data.value.svalue, spec->precision.value);
}
