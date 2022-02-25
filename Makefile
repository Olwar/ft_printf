# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olwar <olwar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 14:43:10 by oairola           #+#    #+#              #
#    Updated: 2022/02/25 08:44:37 by olwar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_cutter.c ft_error_exit.c ft_literally_do_nothing.c \
ft_printf.c ft_putchar_printf.c ft_putfloat.c ft_puthash.c ft_puthexa_lower.c \
ft_puthexa_upper.c ft_putnbr_printf.c ft_putoctal.c ft_putperc.c \
ft_putpointer.c ft_putsign.c ft_putspace.c ft_putstr_printf.c ft_putwidth.c \
ft_putzerofill.c

OBJECTS = $(SOURCES:.c=.o)

HEADERS = ft_printf.h

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@clang -Wall -Wextra -Werror -c $(SOURCES)
	@ar rc $(NAME) $(OBJECTS)

clean:
	@/bin/rm -f $(OBJECTS)
	@make -C ./libft/ clean

fclean: clean/
	@/bin/rm -f $(NAME)
	@make -C ./libft/ fclean

re:fclean all
