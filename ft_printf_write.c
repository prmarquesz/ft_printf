/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:09:34 by proberto          #+#    #+#             */
/*   Updated: 2021/07/23 16:06:23 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_prec(t_spec *spec);
static void	ft_write_width(t_spec *spec);

void	ft_write_int(t_spec *spec)
{
	if ((spec->data.token == 'd' || spec->data.token == 'i')
		&& (spec->data.value.value < 0 && spec->width.fill == '0'))
		spec->count += ft_putchar_fd('-', 1);
	if ((spec->flag.status == ON && spec->flag.token == '0'
			&& spec->data.type != PTR) || (spec->flag.status == OFF))
		ft_write_width(spec);
	if (spec->data.token == 'p')
		spec->count += ft_putstr_fd("0x", 1);
	if (spec->data.type == PTR && spec->flag.status == ON
		&& spec->flag.token == '0')
		ft_write_width(spec);
	if ((spec->data.token == 'd' || spec->data.token == 'i')
		&& (spec->data.value.value < 0 && spec->width.fill == ' '
			&& spec->precision.value))
		spec->count += ft_putchar_fd('-', 1);
	ft_write_prec(spec);
	if (spec->data.value.value || spec->data.value.pvalue)
	{
		if ((spec->data.base == 10 && spec->data.token != 'u')
			&& (spec->width.fill == ' ' && !spec->precision.value))
			spec->count += ft_putnbr_fd(spec->data.value.value, 1);
		else if ((spec->data.base == 10 && spec->data.token != 'u')
			&& (spec->width.fill == '0' || spec->precision.value))
		{
			if (spec->data.value.value > 0)
				spec->count += ft_putnbr_fd(spec->data.value.value, 1);
			else if (spec->data.value.value < 0)
			{
				spec->data.value.value *= -1;
				spec->count += ft_putpnbr_fd(spec->data.value.uvalue, 1);
			}
		}
		else if ((spec->data.base == 10) && (spec->data.token == 'u'))
			spec->count += ft_putpnbr_fd(spec->data.value.uvalue, 1);
		else if ((spec->data.base == 16) && (spec->data.token != 'p'))
			spec->count += ft_putx_fd(spec->data.value.uvalue,
					spec->data.token, 1);
		else if ((spec->data.base == 16) && (spec->data.token == 'p'))
			spec->count += ft_putlx_fd(spec->data.value.pvalue, 1);
	}
	if ((spec->flag.status == ON && spec->flag.token == '-')
		|| (spec->data.type == PTR && spec->flag.token == '0'))
		ft_write_width(spec);
}

static void	ft_write_prec(t_spec *spec)
{
	if ((spec->data.token == 'd' || spec->data.token == 'i')
		&& (spec->data.value.value < 0))
	{
		while (spec->data.length.digits - 1 < spec->precision.value)
		{
			spec->count += ft_putchar_fd(spec->precision.fill, 1);
			spec->data.length.digits++;
		}
		return ;
	}
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
		if ((spec->data.token == 'd' || spec->data.token == 'i')
			&& (spec->data.value.value < 0))
		{
			while ((spec->width.value > spec->precision.value + 1)
				&& (spec->width.value > spec->data.length.digits))
			{
				spec->count += ft_putchar_fd(spec->width.fill, 1);
				spec->width.value--;
			}
			return ;
		}
		while ((spec->width.value > spec->precision.value)
			&& (spec->width.value > spec->data.length.digits))
		{
			spec->count += ft_putchar_fd(spec->width.fill, 1);
			spec->width.value--;
		}
	}
}
