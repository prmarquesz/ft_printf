/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:02:58 by proberto          #+#    #+#             */
/*   Updated: 2021/06/08 01:54:18 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	res = i;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\f' || *(str + i) == '\n'
		|| *(str + i) == '\r' || *(str + i) == '\t' || *(str + i) == '\v')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (ft_isdigit(str[i]))
		res = res * 10 + (*(str + i++) - '0');
	if (LONG_MIN / 10 >= res && sign == 1)
		return ((int)LONG_MAX);
	else if (LONG_MIN / 10 >= res && sign == -1)
		return ((int)LONG_MIN);
	return ((int)res * sign);
}
