# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 16:59:22 by changhyl          #+#    #+#              #
#    Updated: 2022/12/15 22:43:00 by changhyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_printf_utils.c ft_putnbr_fd.c ft_put_u_nbr_fd.c ft_ll_convert_base.c ft_convert_base.c ft_printf_num_p.c ft_printf_print.c ft_printf.c
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:
	$(MAKE)	fclean
	$(MAKE)	all

.PHONY: all clean fclean re
