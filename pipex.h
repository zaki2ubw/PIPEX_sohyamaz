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
	int				exit_code;
	pid_t			pid;
} t_node;

//typedef struct s_fds
//{
//	int				fd;
//	int				state;
//} t_fds;

typedef struct s_mfds //m means mandatory
{
	int				pipefd[2][2];
	int				fdstate[2];
} t_mfds;

typedef struct s_parent
{
	struct s_node	*arg_head;
	char			**path;
	struct s_node	*in;
	struct s_node	*out;
	struct s_mfds	*fds;
	int				cmds;
} t_parent;
