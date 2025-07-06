/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:27 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/07/06 15:13:18 by sohyamaz         ###   ########.fr       */
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
	char	*cmd;

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

char	*access_check(char *cmd)
{
	int		check;
	char	*full;

	check = access(cmd, X_OK);
	if (check == -1)
		return (NULL);
	full = ft_strdup(cmd);
	if (full == NULL)
		return (NULL);
	return (full);
}

char	*find_path(t_structs *var, char *cmd)
{
	char	*tmp;
	char	*full;
	int		count;
	int		check;

	count = 0;
	while (var->path->dirs[count] != NULL)
	{
		tmp = ft_strjoin(var->path->dirs[count], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		check = access(full, X_OK);
		if (check = -1)
		{
			free (full);
			return (NULL);
		}
		else if (check == 0)
			return (full);
		free(full);
		count++;
	}
	return (NULL);
}

char	*check_cmd(t_structs *var, char *cmd)
{
	char	*tmp;

	tmp = ft_strchr(cmd, '/');
	if (tmp != NULL)
		tmp = access_check(cmd);
	else
		tmp = find_path(var, cmd);
	return (tmp);
}
