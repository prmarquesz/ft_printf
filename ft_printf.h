/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:41:03 by proberto          #+#    #+#             */
/*   Updated: 2021/07/24 00:55:55 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define ON		1
# define OFF	0
# define CHR	-1
# define STRING	-2
# define INTEG	-3
# define UINTEG	-4
# define PTR	-5

typedef struct s_flag
{
	int		status;
	char	token;
}			t_flag;

typedef struct s_width
{
	unsigned int	value;
	char			fill;	
}					t_width;

typedef struct s_precision
{
	unsigned int	value;
	int				status;
	char			fill;
}					t_precision;

typedef union s_value_type
{
	char			*svalue;
	unsigned int	uvalue;
	uintptr_t		pvalue;
	int				value;
}					t_value_type;

typedef union u_length
{
	unsigned int	digits;
	size_t			len;
}					t_length;

typedef struct s_data
{
	char			token;
	int				type;
	unsigned int	base;
	t_value_type	value;
	t_length		length;
}					t_data;

typedef struct s_spec
{
	size_t		count;
	t_flag		flag;
	t_width		width;
	t_precision	precision;
	t_data		data;
}				t_spec;

int		ft_printf(const char *str, ...);
void	init_struct(t_spec *spec);
char	*get_flag(char *s, t_spec *spec);
char	*get_width(char *str, va_list *arg, t_spec *spec);
char	*get_precision(char *str, va_list *arg, t_spec *spec);
char	*get_data_type(char *str, va_list *arg, t_spec *spec);
void	ft_formatting(t_spec *spec);
void	ft_write_char(t_spec *spec);
void	ft_write_int(t_spec *spec);
void	ft_write_uint(t_spec *spec);
void	ft_write_ptr(t_spec *spec);

#endif