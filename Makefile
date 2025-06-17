# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 14:14:33 by sohyamaz          #+#    #+#              #
#    Updated: 2025/06/17 14:22:18 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Target declaration
NAME	= pipex
SRCS	= srsc/main.c\
		  gnl/get_next_line.c\
		  gnl/get_next_line_utils.c
OBJS	= $(SRCS:%.c=%.o)

#External Libs
LIBDIR	= Libft
LIBNAME = $(LIBDIR)/libft.a

#Conpile
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g -I$(LIBDIR) -Ignl

#Declaration of rules
all	: $(LIBNAME) $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

$(LIBNAME):
	$(MAKE) -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -O0 -c $< -o $@

clean	:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean	: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re	: fclean all

#Phony target declaration
.PHONY	: all re clean fclean
