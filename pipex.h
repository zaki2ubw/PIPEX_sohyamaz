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
	char			*arg;
	char			**cmd;
	char			*fullpath;
	int				num;
	int				vaild;
	int				exec_status;
	int				exit_code;
	int				fd_in;
	int				fd_out;
	pid_t			pid;
} t_node;

typedef struct s_parent
{
	struct s_node	*head;
	char			*path;

