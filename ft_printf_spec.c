/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:27:57 by proberto          #+#    #+#             */
/*   Updated: 2021/07/17 01:57:24 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			get_data_type(char **str, va_list *arg, t_spec *spec);
static void	try_others(char **str, va_list *arg, t_spec *spec);