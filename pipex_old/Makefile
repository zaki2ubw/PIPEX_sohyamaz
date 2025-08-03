# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 14:14:33 by sohyamaz          #+#    #+#              #
#    Updated: 2025/06/19 21:27:48 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCDIR = srcs
SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/init.c \
       $(SRCDIR)/childs.c \
       $(SRCDIR)/check.c \
       $(SRCDIR)/exit.c

OBJS = $(SRCS:.c=.o)

# Libft
LIBFT_DIR = Libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
