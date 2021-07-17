/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:27:57 by proberto          #+#    #+#             */
/*   Updated: 2021/07/17 02:33:03 by proberto         ###   ########.fr       */
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
	return (str);
}

char	*get_precision(char *str, va_list *arg, t_spec *spec)
{
	if (*str == '.')
	{
		spec->precision.status = ON;
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
	}
	else
		str = try_others(str, arg, spec);
	return (str);
}

static char	*try_others(char *str, va_list *arg, t_spec *spec)
{
	if (*str == 'd' || *str == 'i')
	{
		spec->data.token = *str++;
		spec->data.type = INTEG;
		spec->data.value.value = va_arg(*arg, int);
		spec->data.base = 10;
	}
	else if (*str == 'u' || *str == 'x' || *str == 'X')
	{
		spec->data.token = *str++;
		spec->data.type = INTEG;
		spec->data.value.uvalue = va_arg(*arg, unsigned int);
		if (*str == 'u')
			spec->data.base = 10;
		else
			spec->data.base = 16;
	}
	else if (*str == 'p')
	{
		spec->data.token = *str++;
		spec->data.type = INTEG;
		spec->data.value.pvalue = va_arg(*arg, uintptr_t);
		spec->data.base = 16;
	}
	return (str);
}
