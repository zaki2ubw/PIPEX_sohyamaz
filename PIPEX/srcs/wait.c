#include "pipex.h"

int	wait_childs(t_parent *master)
{
	int		i;
	int		status;
	int		exitcode;
	t_node	*current;

	if (master == NULL)
		error_exit("NULL", master);
	i = 0;
	exitcode = 0;
	status = 0;
	current = master->in->next;
	while (i < master->cmds && current != master->out)
	{
		if (current->pid > 0)
			waitpid(current->pid, &status, 0);
		current = current->next;
		i++;
	}
	exitcode = code_checker(status);
	return (exitcode);
}

int	code_checker(int status)
{
	int		checker;
	int		exitcode;

	exitcode = 0;
	checker = 0;
	checker = WIFEXITED(status);
	if (checker != 0)
		exitcode = WEXITSTATUS(status);
	else
	{
		checker = WIFSIGNALED(status);
		if (checker != 0)
			exitcode = 128 + WTERMSIG(status);
	}
	return (exitcode);
}

void	outfile_exit(char *error, t_parent *master)
{
	if (error == NULL)
		perror("NULL");
	else
		perror(error);
	free_all(master);
	exit(1);
}
