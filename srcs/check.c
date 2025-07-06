/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:27 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/07/06 12:15:38 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	format_check(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd \
		("usage:./pipex infile \"cmd1 -op\" \"cmd2 -op\" outfile", 2);
		exit(ERR_BAD_FORMAT);
	}
	return ;
}

void	check_path(t_structs *var, char **envp)
{
	int		count;
	int		skip;

	if (var == NULL || envp == NULL)
		error_exit(&var, ERR_NULL_VALUE_DETECTED);
	skip = 0;
	count = 0;
	while (envp[count] != NULL)
	{
		skip = ft_strncmp(envp[count], "PATH=", 5);
		if (skip == 0)
			break ;
		count++;
	}
	if (envp[count] == NULL)
		error_exit(&var, ERR_PATH_NOT_FOUND);
	var->path->dirs = ft_split(envp[count] + 5, ':');
	if (var->path->dirs == NULL)
		error_exit(&var, ERR_SPLIT_FAILED);
	return ;
}

char	*check_cmd(t_structs *var, char *cmd)
{
	char	*tmp;
	char	*full;
	int		count;
	int		check;

	count = 0;
	check = 0;
	while (var->path->dirs[count] != NULL)
	{
		tmp = ft_strjoin(var->path->dirs[count], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		check = access(full, X_OK);
		if (check = -1)
		{
			free (full);
			error_exit(&var, ERR_ACCESS_FAILED);
		}
		else if (check == 0)
			return (full);
		free(full);
		count++;
	}
	return (NULL);
}
