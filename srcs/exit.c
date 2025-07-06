/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:50:14 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/07/06 12:01:46 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closing_fds(t_structs *var)
{
	int	i;

	i = 0;
	if (var->fd->fd_in > 0)
		close (var->fd->fd_in);
	if (var->fd->fd_out > 0)
		close (var->fd->fd_out);
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

void	put_perror(int error)
{
	if (error < 7)
		return ;
	else if (error == 7)
		perror("fork");
	else if (error == 8)
		perror("open");
	else if (error == 9)
		perror("pipe");
	else if (error == 10)
		perror("dup2");
	else if (error == 11)
		perror("access");
	else if (error == 12)
		perror("execve");
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
	else
		put_perror(error);
	free_all(*var);
	exit (error);
}
