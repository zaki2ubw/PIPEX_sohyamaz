#include "pipex.h"

//this func is swap from broken fd to safety one
void	swap_safetyfd(t_parent *master, t_node *cmd, int *readfd)
{
	if (master == NULL || cmd == NULL)
		child_exit("NULL", master);
	if (*readfd < 0)
	{
		*readfd = open("/dev/null", O_RDONLY);
		if (*readfd < 0)
			child_exit("open", master);
	}
	if (cmd->writefd < 0)
	{
		if (cmd->next == master->out)
			exit(127);
		cmd->writefd = open("/dev/null", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd->writefd < 0)
			child_exit("open", master);
	}
	return ;
}
