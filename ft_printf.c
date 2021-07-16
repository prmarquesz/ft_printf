/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:37:15 by proberto          #+#    #+#             */
/*   Updated: 2021/07/16 18:06:14 by proberto         ###   ########.fr       */
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
