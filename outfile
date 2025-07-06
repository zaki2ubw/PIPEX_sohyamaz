/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:05:40 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/19 21:58:59 by sohyamaz         ###   ########.fr       */
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

typedef struct s_structs
{
	struct s_cmd	*cmd;
	struct s_path	*path;
	struct s_fd		*fd;
	struct s_proc	*ps;
}	t_structs;

typedef struct s_cmd
{
	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;
}	t_cmd;

typedef struct s_path
{
	char	**dirs;
	char	*dir;
	char	**cmd1;
	char	**cmd2;
	char	*fullpath1;
	char	*fullpath2;
}	t_path;

typedef struct s_fd
{
	int	fd_in;
	int	fd_out;
	int	pipefd[2];
}	t_fd;

typedef struct s_proc
{
	pid_t	pid1;
	pid_t	pid2;
}	t_proc;

# define ERR_BAD_FORMAT 1
# define ERR_NULL_VALUE_DETECTED 2
# define ERR_ALLOCATE_FAILED 3
# define ERR_PATH_NOT_FOUND 4
# define ERR_SPLIT_FAILED 5
# define ERR_INVALID_CMD 6
# define ERR_FORK_FAILED 7
# define ERR_INVALID_INFILE 8
# define ERR_INVALID_OUTFILE 9
# define ERR_PIPE_FAILED 10

//check.c
void	format_check(int argc);
void	check_path(t_structs *var, char **envp);
char	*check_cmd(t_structs *var, char *cmd);

//childs.c
void	exec_childs(t_structs *var, char **argv, char **envp);
void	exec_first_cmd(t_structs *var, char **envp);
void	exec_second_cmd(t_structs *var, char **envp);

//exit.c	
void	closing_fds(t_structs *var);
void	free_all(t_structs *var);
void	error_exit(t_structs **var, int error);

//init.c
void	start_childs(t_structs *var);
void	init_var(t_structs *var);
void	init_structs(t_structs **var, char **argv);

#endif
