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
			current->writefd = pipefd[1];
			current->pid = fork_child(master, current, readfd, pipefd[0]);
			current->pipefd = pipefd;
			readfd = cleanup_fds(readfd, pipefd);
		}
		current = current->next;
	}
	if (readfd > 1)
		close(readfd);
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

int		open_file(t_parent *master, t_node *file)
{
	int		check;

	if (master == NULL || file == NULL)
		child_exit("NULL", master);
	if (file == master->in)
		check = open(file->value, O_RDONLY);
	else
		check = open(file->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fprintf(stderr, "DEBUG: open %s => fd=%d, errno=%d\n",file->value, check, errno);
	if (check < 0 && file == master->in)
		child_exit("open", master);
	else if (check < 0 && file == master->out)
		outfile_exit("open", master);
	return (check);
}

int		cleanup_fds(int readfd, int *pipefd)
{
	int		check;

	if (pipefd == NULL)
		return (-1);
	check = 0;
	if (readfd > 0)
	{
		check = close(readfd);
		if (check < 0)
			perror("close");
	}
	if (pipefd[1] > 0)
	{
		check = close(pipefd[1]);
		if (check < 0)
			perror("close");
	}
	return (pipefd[0]);
}

void	exec_child(t_parent *master, t_node *cmd, int readfd, int unusefd)
{
	if (master == NULL || cmd == NULL)
		child_exit("NULL", master);
	if (readfd < 0 || cmd->writefd < 0)
		child_exit("open", master);
		//swap_safetyfd(master, cmd, &readfd);
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
