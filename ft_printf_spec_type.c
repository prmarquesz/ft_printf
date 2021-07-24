/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:06:34 by proberto          #+#    #+#             */
/*   Updated: 2021/07/23 20:47:42 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_char(char *str, va_list *arg, t_spec *spec);
static char	*get_int(char *str, va_list *arg, t_spec *spec);
static char	*get_uint(char *str, va_list *arg, t_spec *spec);
static char	*get_ptr(char *str, va_list *arg, t_spec *spec);

char	*get_data_type(char *str, va_list *arg, t_spec *spec)
{
	if (*str == '%' || *str == 'c' || *str == 's')
		str = get_char(str, arg, spec);
	else if (*str == 'd' || *str == 'i')
		str = get_int(str, arg, spec);
	else if (*str == 'u' || *str == 'x' || *str == 'X')
		str = get_uint(str, arg, spec);
	else if (*str == 'p')
		str = get_ptr(str, arg, spec);
	else
		spec->data.type = 1;
	if (spec->data.type == INTEG || spec->data.type == UINTEG
		|| spec->data.type == PTR)
	{
		if ((!spec->data.value.value) && (spec->precision.status == OFF))
			spec->precision.value = 1;
	}	
	return (str);
}

static char	*get_char(char *str, va_list *arg, t_spec *spec)
{
	if (*str == '%' || *str == 'c')
	{
		spec->data.token = *str;
		spec->data.type = CHR;
		if (*str == '%')
			spec->data.value.value = *str++;
		else
		{
			spec->data.value.value = va_arg(*arg, int);
			str++;
		}
	}
	else
	{
		spec->data.token = *str++;
		spec->data.type = STRING;
		spec->data.value.svalue = va_arg(*arg, char *);
		if (!spec->data.value.svalue)
			spec->data.value.svalue = "(null)";
		if (spec->precision.status == OFF)
			spec->precision.value = ft_strlen(spec->data.value.svalue);
	}
	return (str);
}

static char	*get_int(char *str, va_list *arg, t_spec *spec)
{
	spec->data.token = *str++;
	spec->data.type = INTEG;
	spec->data.base = 10;
	spec->data.value.value = va_arg(*arg, int);
	return (str);
}

static char	*get_uint(char *str, va_list *arg, t_spec *spec)
{
	spec->data.token = *str++;
	spec->data.type = UINTEG;
	if (spec->data.token == 'u')
		spec->data.base = 10;
	else
		spec->data.base = 16;
	spec->data.value.uvalue = va_arg(*arg, unsigned int);
	return (str);
}

static char	*get_ptr(char *str, va_list *arg, t_spec *spec)
{
	spec->data.token = *str++;
	spec->data.type = PTR;
	spec->data.base = 16;
	spec->data.value.pvalue = va_arg(*arg, uintptr_t);
	return (str);
}
