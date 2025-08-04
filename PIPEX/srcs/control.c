/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:37:47 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/08/04 18:37:53 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *error, t_parent *master)
{
	t_node	*current;

	if (master == NULL)
		exit (1);
	current = master->in;
	perror(error);
	while (current != NULL)
	{
		if (current->pipefd != NULL)
			close_pipefd(current->pipefd);
		current = current->next;
	}
	free_all(master);
	exit (1);
}

void	free_all(t_parent *master)
{
	t_node	*current;
	t_node	*next;

	if (master == NULL)
		exit (1);
	current = master->in;
	while (current != NULL)
	{
		next = current->next;
		if (current->pipefd != NULL)
			close_pipefd(current->pipefd);
		if (current->fullpath != NULL && current->fullpath != current->cmd[0])
			free(current->fullpath);
		free_strs(current->cmd);
		free(current);
		current = next;
	}
	free_strs(master->path);
	free(master);
	return ;
}

void	close_pipefd(int *pipefd)
{
	if (pipefd != NULL && pipefd[0] > 1)
		close(pipefd[0]);
	if (pipefd != NULL && pipefd[1] > 1)
		close(pipefd[1]);
	return ;
}

void	free_strs(char **str)
{
	int		i;

	i = 0;
	if (str == NULL || *str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	if (str != NULL)
		free(str);
	return ;
}

void	child_exit(char *error, t_parent *master)
{
	t_node	*current;

	if (master == NULL)
		exit (1);
	current = master->in;
	if (error == NULL)
		perror("NULL");
	else
		perror(error);
	while (current != NULL)
	{
		if (current->pipefd != NULL)
			close_pipefd(current->pipefd);
		current = current->next;
	}
	free_all(master);
	exit(127);
}
