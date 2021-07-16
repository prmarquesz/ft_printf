/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:09:34 by proberto          #+#    #+#             */
/*   Updated: 2021/07/16 17:57:14 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(t_spec *spec);
void	ft_write_string(t_spec *spec);
void	ft_write_int10(t_spec *spec);
void	ft_write_int16(t_spec *spec);
void	ft_write_ptr(t_spec *spec);
