#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "Libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	char			*value;
	char			**cmd;
	char			*fullpath;
	int				writefd;
	pid_t			pid;
} t_node;

typedef struct s_parent
{
	struct s_node	*arg_head;
	struct s_node	*in;
	struct s_node	*out;
	char			**path;
	int				cmds;
	int				exit_code;
} t_parent;
