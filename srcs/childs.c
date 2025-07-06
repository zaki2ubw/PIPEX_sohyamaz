/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:45:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/07/06 15:20:10 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_childs(t_structs *var, char **argv, char **envp)
{
	if (var == NULL || argv == NULL || envp == NULL)
		error_exit(&var, ERR_NULL_VALUE_DETECTED);
	if (var->ps->pid1 == 0)
		exec_first_cmd(var, envp);
	if (var->ps->pid2 == 0)
		exec_second_cmd(var, envp);
	close_parents_fd(var, var->fd->pipefd[0]);
	close_parents_fd(var, var->fd->pipefd[1]);
	waitpid(var->ps->pid1, NULL, 0);
	waitpid(var->ps->pid2, NULL, 0);
	return ;
}

void	childs_dup(int old, int latest)
{
	int	error;

	error = dup2(old, latest);
	if (error == -1)
	{
		perror("dup2");
		exit(ERR_DUP2_FAILED);
	}
	return ;
}

void	exec_first_cmd(t_structs *var, char **envp)
{
	childs_dup(var->fd->fd_in, STDIN_FILENO);
	childs_dup(var->fd->pipefd[1], STDOUT_FILENO);
	close_childs_fd(var, var->fd->pipefd[0]);
	close_childs_fd(var, var->fd->pipefd[1]);
	var->path->cmd1 = ft_split(var->cmd->cmd1, ' ');
	if (var->path->cmd1 == NULL)
		exit(ERR_SPLIT_FAILED);
	var->path->fullpath1 = check_cmd(var, var->path->cmd1[0]);
	if (var->path->fullpath1 == NULL)
	{
		perror("access");
		exit (ERR_INVALID_CMD);
	}
	execve(var->path->fullpath1, var->path->cmd1, envp);
	perror("execve");
	exit(127);
}

void	exec_second_cmd(t_structs *var, char **envp)
{
	childs_dup(var->fd->pipefd[0], STDIN_FILENO);
	childs_dup(var->fd->fd_out, STDOUT_FILENO);
	close_childs_fd(var, var->fd->pipefd[0]);
	close_childs_fd(var, var->fd->pipefd[1]);
	var->path->cmd2 = ft_split(var->cmd->cmd2, ' ');
	if (var->path->cmd2 == NULL)
		exit(ERR_SPLIT_FAILED);
	var->path->fullpath2 = check_cmd(var, var->path->cmd2[0]);
	if (var->path->fullpath2 == NULL)
	{
		perror("access");
		exit (ERR_INVALID_CMD);
	}
	execve(var->path->fullpath2, var->path->cmd2, envp);
	perror("execve");
	exit(127);
}
