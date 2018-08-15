# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 16:13:26 by mtshisw           #+#    #+#              #
#    Updated: 2018/08/08 15:24:14 by mtshisw          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS = ft_putchar_fd.c ft_putchar.c ft_strlen.c ft_isspace.c\
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	   ft_islower.c ft_isupper.c ft_tolower.c ft_toupper.c ft_strcat.c\
	   ft_strncat.c ft_atoi.c ft_putstr.c ft_putstr_fd.c ft_putnbr_fd.c\
	   ft_putnbr.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strcpy.c\
	   ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_putendl.c\
	   ft_putendl_fd.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
	   ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c\
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	   ft_strjoin.c ft_strtrim.c ft_strlcat.c ft_strnstr.c ft_itoa.c\
	   ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c\
	   ft_lstdel.c ft_strnlen.c ft_strlenc.c get_next_line.c

OBJS = ft_putchar_fd.o ft_putchar.o ft_strlen.o ft_isspace.o\
	   ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
	   ft_islower.o ft_isupper.o ft_tolower.o ft_toupper.o ft_strcat.o\
	   ft_strncat.o ft_atoi.o ft_putstr.o ft_putstr_fd.o ft_putnbr_fd.o\
	   ft_putnbr.o ft_strchr.o ft_strrchr.o ft_strdup.o ft_strcpy.o\
	   ft_strncpy.o ft_strcmp.o ft_strncmp.o ft_strstr.o ft_putendl.o\
	   ft_putendl_fd.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o\
	   ft_memmove.o ft_memchr.o ft_memcmp.o ft_memalloc.o ft_memdel.o\
	   ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o\
	   ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o\
	   ft_strjoin.o ft_strtrim.o ft_strlcat.o ft_strnstr.o ft_itoa.o\
	   ft_strsplit.o ft_lstnew.o ft_lstdelone.o ft_lstadd.o ft_lstiter.o\
	   ft_lstdel.o ft_strnlen.o ft_strlenc.o get_next_line.o

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
