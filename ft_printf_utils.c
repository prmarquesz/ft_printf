/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:46:06 by proberto          #+#    #+#             */
/*   Updated: 2021/07/18 18:18:11 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	intlen(t_spec *spec);
static unsigned int	uintlen(t_spec *spec);
static unsigned int	ptrlen(t_spec *spec);

void	ft_formatting(t_spec *spec)
{
	if (spec->data.type == CHR)
	{
		spec->data.length.len = 1;
		spec->precision.value = 0;
	}
	else if (spec->data.type == STRING)
		spec->data.length.len = ft_strlen(spec->data.value.svalue);
	else if ((spec->data.type == INTEG)
		&& (spec->data.token == 'd' || spec->data.token == 'i'))
		spec->data.length.digits = intlen(spec);
	else if ((spec->data.type == INTEG)
		&& (spec->data.token != 'd' && spec->data.token != 'i'))
		spec->data.length.digits = uintlen(spec);
	else if (spec->data.type == PTR)
		spec->data.length.digits = ptrlen(spec) + 2;
	if (spec->data.type == INTEG || spec->data.type == PTR)
	{
		if (spec->flag.status == ON && spec->flag.token == '0'
			&& spec->precision.status == ON)
		{
			spec->flag.status == OFF;
			spec->width.fill = ' ';
		}
	}
}

static unsigned int	intlen(t_spec *spec)
{
	unsigned int	digits;
	int				n;

	n = spec->data.value.value;
	digits = 0;
	while (n)
	{
		n /= spec->data.base;
		digits++;
	}
	return (digits);
}

static unsigned int	uintlen(t_spec *spec)
{
	unsigned int	digits;
	unsigned int	n;

	n = spec->data.value.uvalue;
	digits = 0;
	while (n)
	{
		n /= spec->data.base;
		digits++;
	}
	return (digits);
}

static unsigned int	ptrlen(t_spec *spec)
{
	unsigned int	digits;
	uintptr_t		n;

	n = spec->data.value.pvalue;
	digits = 0;
	while (n)
	{
		n /= spec->data.base;
		digits++;
	}
	return (digits);
}
