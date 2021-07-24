/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:44:12 by proberto          #+#    #+#             */
/*   Updated: 2021/07/23 23:30:55 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_width(t_spec *spec);
static void	write_prec(t_spec *spec);

void	ft_write_int(t_spec *spec)
{
	if ((spec->data.value.value < 0) && (spec->width.fill == '0'))
		spec->count += ft_putchar_fd('-', 1);
	if ((spec->flag.token == '0') || (spec->flag.status == OFF))
		write_width(spec);
	if ((spec->data.value.value < 0) && (spec->width.fill == ' ')
		&& (spec->precision.value))
		spec->count += ft_putchar_fd('-', 1);
	write_prec(spec);
	if (spec->data.value.value)
	{
		if ((spec->width.fill == ' ') && (!spec->precision.value))
			spec->count += ft_putnbr_fd(spec->data.value.value, 1);
		else if ((spec->width.fill == '0') || (spec->precision.value))
		{
			if (spec->data.value.value > 0)
				spec->count += ft_putnbr_fd(spec->data.value.value, 1);
			else if (spec->data.value.value < 0)
			{
				spec->data.value.value *= -1;
				spec->count += ft_putpnbr_fd(spec->data.value.uvalue, 1);
			}
		}
	}
	if (spec->flag.status == ON && spec->flag.token == '-')
		write_width(spec);
}

static void	write_width(t_spec *spec)
{
	if (spec->data.value.value < 0)
	{
		while ((spec->width.value > spec->precision.value + 1)
			&& (spec->width.value > spec->data.length.digits))
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

static void	write_prec(t_spec *spec)
{
	if (spec->data.value.value < 0)
	{
		while (spec->data.length.digits - 1 < spec->precision.value)
		{
			spec->count += ft_putchar_fd(spec->precision.fill, 1);
			spec->data.length.digits++;
		}
	}
	else
	{
		while (spec->data.length.digits < spec->precision.value)
		{
			spec->count += ft_putchar_fd(spec->precision.fill, 1);
			spec->data.length.digits++;
		}
	}
}
