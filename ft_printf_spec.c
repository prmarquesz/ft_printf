/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:27:57 by proberto          #+#    #+#             */
/*   Updated: 2021/07/16 17:58:02 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_flag(char **str, t_spec *spec);
void		get_width(char **str, t_spec *spec);
void		get_precision(char **str, t_spec *spec);
int			get_data_type(char **str, va_list *arg, t_spec *spec);
static void	try_others(char **str, va_list *arg, t_spec *spec);