/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:09:34 by proberto          #+#    #+#             */
/*   Updated: 2021/07/22 01:43:09 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_prec(t_spec *spec);
static void	ft_write_width(t_spec *spec);

void	ft_write_char(t_spec *spec)
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

void	ft_write_str(t_spec *spec)
{
	if (spec->flag.status == ON && spec->flag.token == '-')
	{
		if ((spec->precision.value >= spec->data.length.len)
			|| (spec->precision.status == OFF))
			spec->count += ft_putstr_fd(spec->data.value.svalue, 1);
		else
		{
			write(1, spec->data.value.svalue, spec->precision.value);
			spec->count += spec->precision.value;
		}
		while (spec->width.value-- > spec->precision.value)
			spec->count += ft_putchar_fd(spec->width.fill, 1);
		return ;
	}
	while (spec->width.value-- > spec->precision.value)
		spec->count += ft_putchar_fd(spec->width.fill, 1);
	if ((spec->precision.value >= spec->data.length.len)
		|| (spec->precision.status == OFF))
		spec->count += ft_putstr_fd(spec->data.value.svalue, 1);
	else
	{
		write(1, spec->data.value.svalue, spec->precision.value);
		spec->count += spec->precision.value;
	}
}

void	ft_write_int(t_spec *spec)
{
	if ((spec->flag.status == ON && spec->flag.token == '0'
			&& spec->data.type != PTR) || (spec->flag.status == OFF))
		ft_write_width(spec);
	if (spec->data.token == 'p')
		spec->count += ft_putstr_fd("0x", 1);
	if (spec->data.type == PTR && spec->flag.status == ON
		&& spec->flag.token == '0')
		ft_write_width(spec);
	ft_write_prec(spec);
	if (spec->data.value.value)
	{
		if ((spec->data.base == 10) && (spec->data.token != 'u'))
			spec->count += ft_putnbr_fd(spec->data.value.value, 1);
		else if ((spec->data.base == 10) && (spec->data.token == 'u'))
			spec->count += ft_putpnbr_fd(spec->data.value.uvalue, 1);
		else if ((spec->data.base == 16) && (spec->data.token != 'p'))
			spec->count += ft_putx_fd(spec->data.value.uvalue, spec->data.token, 1);
		else if ((spec->data.base == 16) && (spec->data.token == 'p'))
			spec->count += ft_putlx_fd(spec->data.value.pvalue, 1);
	}
	if ((spec->flag.status == ON && spec->flag.token == '-')
		|| (spec->data.type == PTR && spec->flag.token == '0'))
		ft_write_width(spec);
}

static void	ft_write_prec(t_spec *spec)
{
	while (spec->data.length.digits < spec->precision.value)
	{
		spec->count += ft_putchar_fd(spec->precision.fill, 1);
		spec->data.length.digits++;
	}
}

static void	ft_write_width(t_spec *spec)
{
	if (spec->data.type == PTR)
	{
		while ((spec->width.value > spec->precision.value + 2)
			&& (spec->width.value > spec->data.length.digits + 2))
		{
			spec->count += ft_putchar_fd(spec->width.fill, 1);
			spec->width.value--;
		}
	}
	else
	{
		while ((spec->width.value > spec->precision.value)
			&& (spec->width.value > spec->data.length.digits))
		{
			spec->count += ft_putchar_fd(spec->width.fill, 1);
			spec->width.value--;
		}
	}
}
