/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:38:57 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/08/04 18:39:00 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				*pipefd;
	pid_t			pid;
}	t_node;

typedef struct s_parent
{
	struct s_node	*arg_head;
	struct s_node	*in;
	struct s_node	*out;
	char			**path;
	char			**envp;
	int				cmds;
}	t_parent;

//childs.c
void	swap_safetyfd(t_parent *master, t_node *cmd, int *readfd);
int		open_file(t_parent *master, t_node *file);
void	dup_fds(t_parent *master, t_node *cmd, int readfd, int unusefd);
void	split_cmd(t_parent *master, t_node *cmd);
void	check_cmdtype(t_parent *master, t_node *cmd);
void	find_cmd(t_parent *master, t_node *cmd);

//control.c
void	error_exit(char *error, t_parent *master);
void	free_all(t_parent *master);
void	child_exit(char *error, t_parent *master);
void	free_strs(char **str);
void	close_pipefd(int *pipefd);

//init.c
void	check_argc(int argc);
void	init_parent(int argc, t_parent **master);
void	make_list(t_parent *master);
void	place_args(int argc, char **argv, t_parent *master);
void	split_env(char **envp, t_parent *master);

// procs.c
void	make_procs(t_parent *master);
pid_t	fork_child(t_parent *master, t_node *cmd, int readfd, int unusefd);
void	make_pipe(t_parent *master, int *pipefd);
int		cleanup_fds(int readfd, int *pipefd);
void	exec_child(t_parent *master, t_node *cmd, int readfd, int unusefd);

//wait.c
int		wait_childs(t_parent *master);
int		code_checker(int status);
void	outfile_exit(char *error, t_parent *master);

#endif
