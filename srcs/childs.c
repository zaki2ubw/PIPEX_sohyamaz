#include "pipex.h"

void	swap_safetyfd(t_parent *master, t_node *cmd, int *readfd)
{
	if (master == NULL || cmd == NULL)
		child_exit("NULL");
	if (*readfd < 0)
		*readfd = open("/dev/null", O_RDONLY);
	if (cmd->writefd < 0)
	{
		if (cmd->next == master->out)
			exit(127);
		cmd->writefd = open("/dev/null", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	return ;
}

void	dup_fds(t_parent *master, t_node *cmd, int readfd, int unusefd)
{
	int		check;

	if (master == NULL || cmd == NULL)
		child_exit("NULL");
	check = 0;
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
	char	*tmp;

	if (master == NULL || cmd == NULL)
		child_exit("NULL");
	cmd->cmd = ft_split(cmd->value, ' ');
	if (cmd->cmd == NULL)
		child_exit("NULL");
	return ;
}

void	check_cmdtype(t_parent *master, t_node *cmd)
{
	char	*tmp;
	int		check;

	if (master == NULL || cmd == NULL)
		child_exit("NULL");
	check = 0;
	tmp = ft_strchr(cmd->cmd[0], '/');
	if (tmp != NULL)
	{
		cmd->fullpath = cmd->cmd[0];
		check = access(cmd->fullpath, X_OK);
		if (check < 0)
			child_exit(cmd->cmd[0]);
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
		child_exit("NULL");
	i = 0;
	while (master->path[i] != NULL)
	{
		dir = ft_strjoin(master->path[i], "/");
		if (dir == NULL)
			child_exit("join");
		full = ft_strjoin(dir, cmd->cmd[0]);
		if (full == NULL)
			child_exit("join");
		free(dir);
		check = access(full, X_OK);
		if (check == 0)
		{
			cmd->fullpath = full;
			return ;
		}
		i++;
	}
	child_exit(cmd->cmd[0]);
}
