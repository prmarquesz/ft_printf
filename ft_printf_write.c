/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:09:34 by proberto          #+#    #+#             */
/*   Updated: 2021/07/18 20:51:45 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(t_spec *spec, size_t *count)
{
	if (spec->flag.status == ON && spec->flag.token == '-')
	{
		*count += ft_putchar_fd(spec->data.value.value, 1);
		while (spec->width.value-- > spec->data.length.len)
			*count += ft_putchar_fd(spec->width.fill, 1);
	}
	else
	{
		while (spec->width.value-- > spec->data.length.len)
			*count += ft_putchar_fd(spec->width.fill, 1);
		*count += ft_putchar_fd(spec->data.value.value, 1);
	}
}

void	ft_write_string(t_spec *spec, size_t *count);
void	ft_write_int10(t_spec *spec, size_t *count);
void	ft_write_int16(t_spec *spec, size_t *count);
void	ft_write_ptr(t_spec *spec, size_t *count);
