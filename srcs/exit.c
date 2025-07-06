/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:50:14 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/07/06 15:17:09 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closing_fds(t_structs *var)
{
	int	i;

	if (var == NULL)
		error_exit(&var, ERR_NULL_VALUE_DETECTED);
	i = 0;
	if (var->fd->fd_in > 0)
		close_parent_fd(var, var->fd->fd_in);
	if (var->fd->fd_out > 0)
		close_parent_fd(var, var->fd->fd_out);
	if (var->path->dirs != NULL)
	{
		while (var->path->dirs[i] != NULL)
		{
			free(var->path->dirs[i]);
			i++;
		}
	}
	return ;
}

void	close_parent_fd(t_structs *var, int fd)
{
	int	error;

	error = 0;
	if (var == NULL)
		error_exit(&var, ERR_NULL_VALUE_DETECTED);
	error = close(fd);
	if (error == -1)
	error_exit(&var, ERR_CLOSE_FAILED);
	return ;
}

void	close_childs_fd(int fd)
{
	int	error;

	error = 0;
	error = close(fd);
	if (error == -1)
	{
		perror("close");
		exit (ERR_CLOSE_FAILED);
	}
	return ;
}

void	free_all(t_structs *var)
{
	closing_fds(var);
	free(var->path->dirs);
	free(var->ps);
	free(var->fd);
	free(var->path);
	free(var->cmd);
	free(var);
	return ;
}

void	error_exit(t_structs **var, int error)
{
	if (error < 7)
		ft_putnbr_fd(error, 2);
	else if (error == 7)
		perror("fork");
	else if (error == 8)
		perror("open");
	else if (error == 9)
		perror("pipe");
	free_all(*var);
	exit (error);
}
