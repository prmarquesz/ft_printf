/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:46:06 by proberto          #+#    #+#             */
/*   Updated: 2021/07/23 14:36:10 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_int(t_spec *spec);
static void	format_uint(t_spec *spec);
static void	format_ptr(t_spec *spec);

void	init_struct(t_spec *spec)
{
	spec->flag.status = OFF;
	spec->flag.token = 0;
	spec->width.value = 0;
	spec->width.fill = 0;
	spec->precision.status = OFF;
	spec->precision.value = 0;
	spec->precision.fill = 0;
	spec->data.token = 0;
	spec->data.type = 0;
	spec->data.base = 0;
	spec->data.length.len = 0;
	spec->data.value.svalue = 0;
	spec->data.value.value = 0;
}

void	ft_formatting(t_spec *spec)
{
	if (spec->data.type == CHR)
	{
		spec->data.length.len = 1;
		spec->precision.value = 0;
	}
	else if (spec->data.type == STRING)
	{
		spec->data.length.len = ft_strlen(spec->data.value.svalue);
		if ((int)spec->precision.value < 0)
			spec->precision.value = spec->data.length.len;
	}
	else if ((spec->data.type == INTEG)
		&& (spec->data.token == 'd' || spec->data.token == 'i'))
		format_int(spec);
	else if ((spec->data.type == INTEG)
		&& (spec->data.token != 'd' && spec->data.token != 'i'))
		format_uint(spec);
	else if (spec->data.type == PTR)
		format_ptr(spec);
}

static void	format_int(t_spec *spec)
{
	int				n;

	n = spec->data.value.value;
	spec->data.length.digits = 0;
	while (n)
	{
		n /= (int)spec->data.base;
		spec->data.length.digits++;
	}
	if (spec->data.value.value < 0)
		spec->data.length.digits++;
	if ((int)spec->precision.value < 0)
	{
		spec->precision.value = 0;
		spec->precision.status = OFF;
	}
	if (spec->flag.status == ON && spec->flag.token == '0'
		&& spec->precision.status == ON)
	{
		spec->flag.status = OFF;
		spec->width.fill = ' ';
	}
	if ((!spec->data.value.value) && (spec->precision.status == OFF))
		spec->precision.fill = '0';
}

static void	format_uint(t_spec *spec)
{
	unsigned int	n;

	n = spec->data.value.uvalue;
	spec->data.length.digits = 0;
	while (n)
	{
		n /= spec->data.base;
		spec->data.length.digits++;
	}
	if ((int)spec->precision.value < 0)
	{
		spec->precision.value = 0;
		spec->precision.status = OFF;
	}
	if (spec->flag.status == ON && spec->flag.token == '0'
		&& spec->precision.status == ON)
	{
		spec->flag.status = OFF;
		spec->width.fill = ' ';
	}
	if ((!spec->data.value.value) && (spec->precision.status == OFF))
		spec->precision.fill = '0';
}

static void	format_ptr(t_spec *spec)
{
	uintptr_t		n;

	n = spec->data.value.pvalue;
	spec->data.length.digits = 0;
	while (n)
	{
		n /= spec->data.base;
		spec->data.length.digits++;
	}
	if ((int)spec->precision.value < 0)
		spec->precision.value = 0;
	if (spec->flag.status == ON && spec->flag.token == '0'
		&& spec->precision.status == ON)
	{
		spec->flag.status = OFF;
		spec->width.fill = ' ';
	}
	if ((!spec->data.value.value) && (spec->precision.status == OFF))
		spec->precision.fill = '0';
}
