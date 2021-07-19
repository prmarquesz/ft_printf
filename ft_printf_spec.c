/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:27:57 by proberto          #+#    #+#             */
/*   Updated: 2021/07/19 03:03:12 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*try_others(char *str, va_list *arg, t_spec *spec);

char	*get_flag(char *str, t_spec *spec)
{
	while ((*str == '0' || *str == '-') && spec->flag.token != '-')
	{
		spec->flag.status = ON;
		spec->flag.token = *str++;
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
	else
		spec->width.value = 0;
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
	else
		spec->precision.value = 0;
	return (str);
}

char	*get_data_type(char *str, va_list *arg, t_spec *spec)
{
	if (*str == '%')
	{
		spec->data.token = *str;
		spec->data.type = CHR;
		spec->data.value.value = *str++;
	}
	else if (*str == 'c')
	{
		spec->data.token = *str++;
		spec->data.type = CHR;
		spec->data.value.value = va_arg(*arg, int);
	}
	else if (*str == 's')
	{
		spec->data.token = *str++;
		spec->data.type = STRING;
		spec->data.value.svalue = ft_strdup(va_arg(*arg, char *));
		if (!spec->data.value.svalue)
			return (NULL);
		if (spec->precision.status == OFF)
			spec->precision.value = ft_strlen(spec->data.value.svalue);
	}
	else
		str = try_others(str, arg, spec);
	return (str);
}

static char	*try_others(char *str, va_list *arg, t_spec *spec)
{
	spec->data.type = INTEG;
	if (*str == 'd' || *str == 'i' || *str == 'u')
		spec->data.base = 10;
	else
		spec->data.base = 16;
	if (*str == 'd' || *str == 'i')
		spec->data.value.value = va_arg(*arg, int);
	else if (*str == 'u' || *str == 'x' || *str == 'X')
		spec->data.value.uvalue = va_arg(*arg, unsigned int);
	else if (*str == 'p')
	{
		spec->data.value.pvalue = va_arg(*arg, uintptr_t);
		spec->data.type = PTR;
	}
	else
		spec->data.type = 1;
	if (spec->data.type == INTEG || spec->data.type == PTR)
		spec->data.token = *str++;
	return (str);
}
