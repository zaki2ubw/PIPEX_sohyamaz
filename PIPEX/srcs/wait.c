/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:38:39 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/08/04 20:57:12 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_childs(t_parent *master)
{
	int		i;
	int		status;
	int		exitcode;
	t_node	*current;

	if (master == NULL)
		error_exit("NULL", master);
	i = 0;
	exitcode = 0;
	status = 0;
	current = master->in->next;
	while (i < master->cmds && current != master->out)
	{
		if (current->pid > 0)
			waitpid(current->pid, &status, 0);
		current = current->next;
		i++;
	}
	exitcode = code_checker(status);
	if (master->lastfd > 0)
		close (master->lastfd);
	return (exitcode);
}

int	code_checker(int status)
{
	int		checker;
	int		exitcode;

	exitcode = 0;
	checker = 0;
	checker = WIFEXITED(status);
	if (checker != 0)
		exitcode = WEXITSTATUS(status);
	else
	{
		checker = WIFSIGNALED(status);
		if (checker != 0)
			exitcode = 128 + WTERMSIG(status);
	}
	return (exitcode);
}

void	outfile_exit(char *error, t_parent *master)
{
	t_node	*current;

	if (master == NULL)
		exit (1);
	if (error == NULL)
		perror("NULL");
	else
		perror(error);
	current = master->in;
	while (current != NULL)
	{
		if (current->pipefd != NULL)
			close_pipefd(current->pipefd);
		current = current->next;
	}
	if (master->readfd > 1)
		close (master->readfd);
	if (master->writefd > 1)
		close (master->writefd);
	free_all(master);
	exit(1);
}
