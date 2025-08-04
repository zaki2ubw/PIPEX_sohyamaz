/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:37:38 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/08/04 18:37:40 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_pipe(t_parent *master, int *pipefd)
{
	int		check;

	if (master == NULL || pipefd == NULL)
		error_exit("NULL", master);
	check = pipe(pipefd);
	if (check < 0)
	{
		perror("pipe");
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
	return ;
}

void	dup_fds(t_parent *master, t_node *cmd, int readfd, int unusefd)
{
	int		check;

	if (master == NULL || cmd == NULL)
		child_exit("NULL", master);
	check = 0;
	if (unusefd > 2)
		check = close(unusefd);
	if (check < 0)
		perror("close");
	check = dup2(readfd, STDIN_FILENO);
	if (check < 0)
		perror("dup2");
	check = dup2(cmd->writefd, STDOUT_FILENO);
	if (check < 0)
		perror("dup2");
	check = close(readfd);
	if (check < 0)
		perror("close");
	check = close(cmd->writefd);
	if (check < 0)
		perror("close");
	return ;
}

void	split_cmd(t_parent *master, t_node *cmd)
{
	if (master == NULL || cmd == NULL || cmd->value == NULL)
		child_exit("NULL", master);
	if (cmd->value[0] == '\0')
		child_exit("permission denied", master);
	cmd->cmd = ft_split(cmd->value, ' ');
	if (cmd->cmd == NULL)
		child_exit("NULL", master);
	return ;
}

void	check_cmdtype(t_parent *master, t_node *cmd)
{
	char	*tmp;
	int		check;

	if (master == NULL || cmd == NULL)
		child_exit("NULL", master);
	check = 0;
	tmp = ft_strchr(cmd->cmd[0], '/');
	if (tmp != NULL)
	{
		cmd->fullpath = cmd->cmd[0];
		check = access(cmd->fullpath, X_OK);
		if (check < 0)
			child_exit(cmd->cmd[0], master);
	}
	else
		find_cmd(master, cmd);
	return ;
}

void	find_cmd(t_parent *master, t_node *cmd)
{
	int		i;
	char	*dir;
	char	*full;

	if (master == NULL || cmd == NULL)
		child_exit("NULL", master);
	i = 0;
	while (master->path[i] != NULL)
	{
		dir = ft_strjoin(master->path[i], "/");
		if (dir == NULL)
			child_exit("join", master);
		full = ft_strjoin(dir, cmd->cmd[0]);
		if (full == NULL)
			child_exit("join", master);
		free(dir);
		if (access(full, X_OK) == 0)
		{
			cmd->fullpath = full;
			return ;
		}
		free(full);
		i++;
	}
	child_exit(cmd->cmd[0], master);
}
