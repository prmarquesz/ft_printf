/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:37:15 by proberto          #+#    #+#             */
/*   Updated: 2021/07/22 01:38:32 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_spec(char *str, va_list *arg, t_spec *spec);

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_spec	spec;

	va_start(arg, str);
	spec.count = 0;
	while (*str)
	{
		if (*str != '%')
			spec.count += ft_putchar_fd(*str++, 1);
		else
		{
			str = get_spec((char *)++str, &arg, &spec);
			if (!str)
				break ;
		}
	}
	va_end(arg);
	return (spec.count);
}

static char	*get_spec(char *str, va_list *arg, t_spec *spec)
{
	init_struct(spec);
	str = get_flag(str, spec);
	str = get_width(str, arg, spec);
	str = get_precision(str, arg, spec);
	str = get_data_type(str, arg, spec);
	ft_formatting(spec);
	if (spec->data.type == CHR)
		ft_write_char(spec);
	else if (spec->data.type == STRING)
		ft_write_str(spec);
	else if (spec->data.type == INTEG || spec->data.type == PTR)
		ft_write_int(spec);
	else if (spec->data.type >= 0)
	{
		if (spec->width.value > 0)
			spec->width.value += -1;
		spec->precision.value = 0;
		ft_write_int(spec);
	}
	return (str);
}
