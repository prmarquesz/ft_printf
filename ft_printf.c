/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:37:15 by proberto          #+#    #+#             */
/*   Updated: 2021/07/16 18:22:35 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_spec(char **str, va_list *arg, t_spec *spec, size_t *count);

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_spec	spec;
	size_t	count;

	va_start(arg, str);
	count = 0;
	while (*str)
	{
		if (*str != '%')
			ft_putchar_fd(*str++, 1);
		else
			if(!get_spec((char **)&str, &arg, &spec, &count))
				break ;
	}
	va_end(arg);
	return (count);
}

static int		get_spec(char **str, va_list *arg, t_spec *spec, size_t *count)
{
	get_flag(str, spec);
	get_width(str, spec);
	get_precision(str, spec);
	if (!get_data_type(str, arg, spec))
		return (0);
	ft_formatting(spec);
	if (spec->data.type == CHR)
		ft_write_char(spec);
	else if (spec->data.type == STRING)
		ft_write_string(spec);
	else if (spec->data.type == INTEG && spec->data.base == 10)
		ft_write_int10(spec);
	else if (spec->data.type == INTEG && spec->data.base == 16)
		ft_write_int16(spec);
	else if (spec->data.type == PTR)
		ft_write_ptr(spec);
	if (spec->data.type >= 0)
		return (0);
	else
	{
		*str++;
		return (1);
	}
}
