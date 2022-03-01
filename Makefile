# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olwar <olwar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 14:43:10 by oairola           #+#    #+#              #
#    Updated: 2022/03/01 15:57:48 by olwar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_checkzero.c ft_cutter.c ft_error_exit.c ft_floatlen.c \
ft_hexlen_lower.c ft_hexlen_upper.c ft_justify.c ft_literally_do_nothing.c \
ft_octlen.c ft_printf.c ft_ptrlen.c ft_putchar_printf.c ft_putfloat.c \
ft_puthash.c ft_puthexa_lower.c ft_puthexa_upper.c ft_putnbr_printf.c \
ft_putoctal.c ft_putperc.c ft_putpointer.c ft_putsign.c ft_putspace.c \
ft_putstr_printf.c ft_putwidth.c test_for_printf.c ft_checkzero.c

OBJECTS = $(SOURCES:.c=.o)

LIBSRS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_hypotenuse.c \
libft/ft_intdup.c libft/ft_intlen.c libft/ft_intnew.c libft/ft_inttoarray.c \
libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
libft/ft_isprint.c libft/ft_iswhitespace.c libft/ft_itoa.c libft/ft_lstadd.c \
libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c \
libft/ft_lstnew.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c \
libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c \
libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c \
libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c \
libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c \
libft/ft_sqrt.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c\
libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c \
libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c \
libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c \
libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strndup.c \
libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c\
libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c \
libft/ft_tolower.c libft/ft_toupper.c libft/ft_wordcount.c

LIBOBJS = $(LIBSRS:.c=.o)

HEADERS = ft_printf.h

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@gcc -Wall -Wextra -Werror -c $(SOURCES) -fPIE -I. -I.libft/
	@ar rc $(NAME) $(OBJECTS) $(LIBOBJS)

clean:
	@/bin/rm -f $(OBJECTS)
	@make -C ./libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft/ fclean

re:fclean all
