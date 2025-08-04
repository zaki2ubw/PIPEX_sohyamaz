NAME = pipex
SRCDIR = srcs
SRCS = $(SRCDIR)/childs.c \
       $(SRCDIR)/control.c \
       $(SRCDIR)/init.c \
       $(SRCDIR)/procs.c \
       $(SRCDIR)/wait.c
MMAIN = $(SRCDIR)/main.c
BMAIN = $(SRCDIR)/main_bonus.c

OBJS = $(SRCS:.c=.o)
MOBJ = $(MMAIN:.c=.o)
BOBJ = $(BMAIN:.c=.o)

LIBFT_DIR = Libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(MOBJ)
	$(CC) $(CFLAGS) $(OBJS) $(MOBJ) $(LIBFT_A) -o $(NAME)

bonus: $(LIBFT_A) $(OBJS) $(BOBJ)
	$(CC) $(CFLAGS) $(OBJS) $(BOBJ) $(LIBFT_A) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MOBJ) $(BOBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
