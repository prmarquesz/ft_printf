/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:37:15 by proberto          #+#    #+#             */
/*   Updated: 2021/07/19 02:55:51 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_spec(char *str, va_list *arg, t_spec *spec, size_t *count);

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
			count += ft_putchar_fd(*str++, 1);
		else
		{
			str = get_spec((char *)++str, &arg, &spec, &count);
			if (!str)
				break ;
		}
	}
	if (spec.data.type == STRING)
		free(spec.data.value.svalue);
	va_end(arg);
	return (count);
}

static char	*get_spec(char *str, va_list *arg, t_spec *spec, size_t *count)
{
	str = get_flag(str, spec);
	str = get_width(str, arg, spec);
	str = get_precision(str, arg, spec);
	str = get_data_type(str, arg, spec);
	if (!str)
		return (str);
	ft_formatting(spec);
	if (spec->data.type == CHR)
		ft_write_char(spec, count);
	else if (spec->data.type == STRING)
		ft_write_str(spec, count);
	else if (spec->data.type == INTEG || spec->data.type == PTR)
		ft_write_int(spec, count);
	/*if (spec->data.type >= 0)
		return (0);
	else
	{
		*str++;
		return (1);
	}*/
	return (str);
}
