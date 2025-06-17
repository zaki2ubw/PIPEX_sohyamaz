# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 15:55:00 by sohyamaz          #+#    #+#              #
#    Updated: 2024/11/24 13:32:01 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Target declaration
NAME	= libft.a
SRCS	= ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
	ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
	ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
LIBS	= ar -rcs
OBJS	= $(SRCS:%.c=%.o)

#Declaration of rules

all	: $(NAME)

clean	: 
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all

#Pony target declaration
.PHONY	: all re clean fclean

$(NAME)	: $(OBJS)
	$(LIBS) $(NAME) $^ -o $@

%.o	: %.c
	$(CC) $(CFLAGS) -c $< -o $@
