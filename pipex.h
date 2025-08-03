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
	char			**envp;
	int				cmds;
} t_parent;

//childs.c
void	swap_safetyfd(t_parent *master, t_node *cmd, int *readfd);
void	dup_fds(t_parent *master, t_node *cmd, int readfd, int unusefd);
void	split_cmd(t_parent *master, t_node *cmd);
void	check_cmdtype(t_parent *master, t_node *cmd);
void	find_cmd(t_parent *master, t_node *cmd);

//control.c
void	exec_child(t_parent *master, t_node *cmd, int readfd, int unusefd);
void	error_exit(char *error, t_parent *master);
void	free_all(t_parent *master);
void	child_exit(char *error);

//init.c
void	check_argc(int argc, t_parent *master);
void	init_parent(t_parent **master);
void	make_list(int argc, t_parent *master);
void	place_args(int argc, char **argv, t_parent *master);

// procs,c
void	make_procs(t_parent *master);
t_pid	fork_child(t_parent *master, t_node *cmd, int readfd);
int		open_file(t_parent *master, char *file);
void	*make_pipe(t_parent *master, int *pipefd);
int		cleanup_fds(int readfd, int *pipefd);
void	split_env(char **envp, t_parent *master);

//wait.c
int		wait_childs(t_parent *master);
int		code_checker(int status);
