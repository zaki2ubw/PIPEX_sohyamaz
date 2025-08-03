#include "pipex.h"

void	exec_child(t_parent *master, t_node *cmd, int readfd, int unusefd)
{
	int		check;
	int		absol;

	if (master == NULL || cmd == NULL)
		child_exit("NULL");
	if (readfd < 0 || cmd->writefd < 0)
		swap_safetyfd(master, cmd, &readfd);
	dup_fds(master, cmd, readfd, unusefd);
	split_cmd(master, cmd);
	check_cmdtype(master, cmd);
	execve(cmd->fullpath, cmd->cmd, master->envp);
	child_exit("execve");
}

void	error_exit(char *error, t_parent *master)
{
	perror(error);
	free_all(master);
	exit (1);
}

void	free_all(t_parent *master)
{
	t_node	*current;

	if (master == NULL)
		exit (1);
	current = master->arg_head;
	while (current->next != NULL)
	{
		free(current->fullpath);
		free(current->cmd);
		current = current->next;
		free(current->prev);
	}
	free(current->fullpath);
	free(current->cmd);
	free(current);
	free(master->path);
	free(master);
	return;
}

void	child_exit(char *error)
{
	if (error == NULL)
		perror("NULL");
	else
		perror(error);
	exit(127);
}
