#include "pipex.h"

void	make_procs(t_parent *master)
{
	int		i;
	int		readfd;
	int		pipefd[2];
	t_node	*current;

	if (master == NULL)
		error_exit("NULL", master);
	i = 0;
	current = master->in->next;
	readfd = open_file(master, master->in);
	while (i < master->cmds && current != master->out)
	{
		make_pipe(master, pipefd);
		if (i == master->cmds - 1)
			current->writefd = open_file(master, master->out);
		else
			current->writefd = pipefd[1];
		current->pid = fork_child(master, current, readfd);
		readfd = cleanup_fds(readfd, pipefd);
		current = current->next;
		i++;
	}
	return ;
}

t_pid	fork_child(t_parent *master, t_node *cmd, int readfd)
{
	t_pid	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
		exec_child(master, cmd, readfd);
	return (pid);
}

int		open_file(t_parent *master, char *file)
{
	int		check;

	if (master == NULL || file == NULL)
		error_exit("NULL", master);
	check = open(file, O_RDONLY);
	if (check < 0)
		perror("open");
	return (check);
}

void	*make_pipe(t_parent *master, int *pipefd)
{
	int		check;

	if (master == NULL || current == NULL)
		error_exit("NULL", master);
	check = pipe(pipefd);
	if (check < 0)
	{
		perror("pipe");
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
	return (pipefd);
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
		if (check < 0);
			perror("close");
	}
	if (pipefd[1] > 0)
	{
		check = close(pipefd[1]);
		if (check < 0);
			perror("close");
	}
	return (pipefd[0]);
}

