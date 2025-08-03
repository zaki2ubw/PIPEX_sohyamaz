
NAME = pipex

SRCDIR = srcs
SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/childs.c \
       $(SRCDIR)/control.c \
       $(SRCDIR)/init.c \
       $(SRCDIR)/procs.c \
       $(SRCDIR)/wait.c

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

# ===== Bonus target =====
BONUS_MAIN = srcs/main_bonus.c
BONUS_OBJ  = srcs/main_bonus.o
BONUS_OBJS = $(filter-out srcs/main.o, $(SRCS:.c=.o)) $(BONUS_OBJ)

bonus: $(SRCS:.c=.o) $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS:.c=.o) $(BONUS_OBJ) -L Libft -lft -o $(NAME)

$(BONUS_OBJ): $(BONUS_MAIN)
	$(CC) $(CFLAGS) -c $(BONUS_MAIN) -o $(BONUS_OBJ)
