/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:11:56 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/19 21:58:22 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	start_childs(t_structs *var)
{
	if (var == NULL)
		error_exit(&var, ERR_NULL_VALUE_DETECTED);
	var->ps->pid1 = fork();
	if (var->ps->pid1 == -1)
	{
		perror("fork failed");
		error_exit(&var, ERR_FORK_FAILED);
	}
	var->ps->pid2 = fork();
	if (var->ps->pid2 == -1)
	{
		perror("fork failed");
		error_exit(&var, ERR_FORK_FAILED);
	}
	return ;
}

void	init_var(t_structs *var)
{
	int		flag;

	flag = 0;
	if (var == NULL)
		error_exit(&var, ERR_NULL_VALUE_DETECTED);
	var->fd->fd_in = open(var->cmd->infile, O_RDONLY);
	if (var->fd->fd_in == -1)
	{
		perror("infile open failed");
		error_exit(&var, ERR_INVALID_INFILE);
	}
	var->fd->fd_out = open(var->cmd->outfile, \
	O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var->fd->fd_out == -1)
	{
		perror("outfile open failed");
		error_exit(&var, ERR_INVALID_OUTFILE);
	}
	flag = pipe(var->fd->pipefd);
	if (flag == -1)
	{
		perror("pipe failed");
		error_exit(&var, ERR_PIPE_FAILED);
	}
	return ;
}

void	init_structs(t_structs **var, char **argv)
{
	if (argv == NULL)
		error_exit(var, ERR_NULL_VALUE_DETECTED);
	*var = ft_calloc(sizeof(t_structs), 1);
	if (*var == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->cmd = ft_calloc(sizeof(t_cmd), 1);
	if ((*var)->cmd == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->path = ft_calloc(sizeof(t_path), 1);
	if ((*var)->path == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->fd = ft_calloc(sizeof(t_fd), 1);
	if ((*var)->fd == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->ps = ft_calloc(sizeof(t_proc), 1);
	if ((*var)->ps == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->cmd->infile = argv[1];
	(*var)->cmd->cmd1 = argv[2];
	(*var)->cmd->cmd2 = argv[3];
	(*var)->cmd->outfile = argv[4];
	return ;
}
