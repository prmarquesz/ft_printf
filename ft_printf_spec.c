/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:27:57 by proberto          #+#    #+#             */
/*   Updated: 2021/07/23 17:39:36 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_flag(char *str, t_spec *spec)
{
	while ((*str == '0' || *str == '-'))
	{
		if (spec->flag.status == OFF || spec->flag.token == '0')
			spec->flag.token = *str++;
		else
			str++;
		spec->flag.status = ON;
	}
	if (spec->flag.token == '0')
		spec->width.fill = '0';
	else
		spec->width.fill = ' ';
	return (str);
}

char	*get_width(char *str, va_list *arg, t_spec *spec)
{
	if (ft_isdigit(*str))
	{
		spec->width.value = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	else if (*str == '*')
	{
		spec->width.value = va_arg(*arg, unsigned int);
		str++;
	}
	if ((int)spec->width.value < 0)
	{
		spec->flag.status = ON;
		spec->flag.token = '-';
		spec->width.fill = ' ';
		spec->width.value *= -1;
	}
	return (str);
}

char	*get_precision(char *str, va_list *arg, t_spec *spec)
{
	if (*str == '.')
	{
		spec->precision.status = ON;
		spec->precision.fill = '0';
		str++;
		if (ft_isdigit(*str))
		{
			spec->precision.value = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		else if (*str == '*')
		{
			spec->precision.value = va_arg(*arg, unsigned int);
			str++;
		}
	}
	return (str);
}
