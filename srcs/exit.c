/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:50:14 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/19 22:12:22 by sohyamaz         ###   ########.fr       */
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
	free_all(*var);
	exit (error);
}
