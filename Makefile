# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 13:25:45 by proberto          #+#    #+#              #
#    Updated: 2021/07/20 14:17:18 by proberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_printf_spec.c ft_printf_utils.c ft_printf_write.c
OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(MAKE) -C libft/
	@ar -rcs $@ $(OBJS)

%.o:	%.c
	@$(CC) -c $(CFLAGS) $< -o $@

bonus:	all

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C libft/

fclean:	clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft/

re:	fclean all

.PHONY: all bonus clean fclean re
