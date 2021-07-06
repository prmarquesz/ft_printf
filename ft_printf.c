/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:37:15 by proberto          #+#    #+#             */
/*   Updated: 2021/07/06 15:07:19 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	check_type(char c, va_list *arg, size_t i, size_t *count);

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = check_type(str[i + 1], &arg, i, &count);
			if (i == -1)
				return (count);
		}	
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(arg);
	return (count);
}

static size_t	check_type(char c, va_list *arg, size_t i, size_t *count)
{
	if (c == '%')
		(*count) += ft_putchar_fd(va_arg(*arg, int), 1);
	else if (c == 'c')
		(*count) += ft_putchar_fd(va_arg(*arg, int), 1);
	else if (c == 's')
		(*count) += ft_putstr_fd(va_arg(*arg, char *), 1);
	else if (c == 'd' || c == 'i')
		(*count) += ft_putnbr_fd(va_arg(*arg, int), 1);
	else if (c == 'u')
		(*count) += ft_putpnbr_fd(va_arg(*arg, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		(*count) += ft_putx_fd(va_arg(*arg, unsigned int), c, 1);
	else if (c == 'p')
	{
		(*count) += ft_putstr_fd("0x", 1);
		(*count) += ft_putlx_fd(va_arg(*arg, uintptr_t), 1);
	}
	else
	{
		return (-1);
	}
	return (i + 2);
}
