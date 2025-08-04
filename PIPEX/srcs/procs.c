/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:38:27 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/08/04 20:41:58 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_procs(t_parent *master)
{
	int		readfd;
	int		pipefd[2];
	t_node	*current;

	if (master == NULL)
		error_exit("NULL", master);
	current = master->in->next;
	readfd = 0;
	while (current != master->out)
	{
		if (current->next == master->out)
			current->pid = fork_child(master, current, readfd, -1);
		else
		{
			make_pipe(master, pipefd);
			current->pipefd = pipefd;
			current->writefd = pipefd[1];
			current->pid = fork_child(master, current, readfd, pipefd[0]);
			readfd = cleanup_fds(readfd, pipefd, master, current);
		}
		current = current->next;
	}
	master->lastfd = readfd;
	return ;
}

pid_t	fork_child(t_parent *master, t_node *cmd, int readfd, int unusefd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
		exec_child(master, cmd, readfd, unusefd);
	return (pid);
}

int	open_file(t_parent *master, t_node *file)
{
	int	fd;

	fd = 0;
	if (master == NULL || file == NULL)
		child_exit("NULL", master);
	if (file == master->in)
	{
		master->readfd = open(file->value, O_RDONLY);
		if (master->readfd < 0)
			child_exit("open", master);
		fd = master->readfd;
	}
	else
	{
		master->writefd = open(file->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (master->writefd < 0)
			outfile_exit("open", master);
		fd = master->writefd;
	}
	return (fd);
}

int	cleanup_fds(int readfd, int *pipefd, t_parent *master, t_node *current)
{
	if (master == NULL || current == NULL || pipefd == NULL)
		error_exit("NULL", master);
	if (readfd > 1)
		close(readfd);
	if (pipefd[1] > 1)
		close(pipefd[1]);
	if (current->prev == master->in && pipefd[1] > 1)
		close(pipefd[1]);
	if (current->next == master->out && pipefd[0] > 1)
		close(pipefd[0]);
	return (pipefd[0]);
}

void	exec_child(t_parent *master, t_node *cmd, int readfd, int unusefd)
{
	if (master == NULL || cmd == NULL)
		child_exit("NULL", master);
	if (readfd < 0 || cmd->writefd < 0)
		child_exit("open", master);
	if (cmd == master->in->next)
		readfd = open_file(master, master->in);
	if (cmd == master->out->prev)
		cmd->writefd = open_file(master, master->out);
	dup_fds(master, cmd, readfd, unusefd);
	split_cmd(master, cmd);
	check_cmdtype(master, cmd);
	execve(cmd->fullpath, cmd->cmd, master->envp);
	child_exit("execve", master);
}
