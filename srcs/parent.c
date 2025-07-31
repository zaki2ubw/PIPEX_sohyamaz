#include "pipex.h"

void	check_argc(int argc, t_parent *master)
{
	if (argc != 5)
	{
		ft_putstr_fd("usage:./pipex infile \"cmd1 -op\" \"cmd2 -op\" outfile", 2);
		error_exit("argc", NULL);
	}
	master->cmds = 2;
	//in bonus
	//master->cmds = argc - 3 (exclude ./pipex, infile, outfile)
	return ;
}

void	make_list(int argc, char **argv, t_parent *master)
{
	t_node	*current;
	int		i;

	current = master->arg_head;
	i = 0;
	while (i < (argc - 1))//we do not need ./pipex in list
	{
		current->next = ft_calloc(sizeof(t_node), 1);
		if (current->next == NULL)
			error_exit("ft_calloc", NULL);
		if (i == 0)
			master->in = current;
		else if (i == argc - 2)
		{
			master->out = current;
			current->next = NULL;
			return ;
		}
		current->next->prev = current;
		current = current->next;
		i++;
	}
}

void	place_args(int argc, char **argv, t_parent *master)
{
	int		i;
	t_node	*current;

	i = 1;
	current = master->arg_head;
	while (i < argc)
	{
		current->value = argv[i];
		current = current->next;
		i++;
	}
	return ;
}

void	split_env(char **envp, t_parent *master)
{
	int		i;
	int		check;
	char	*tmp;

	i = 0;
	check = 0;
	tmp = NULL;
	while (envp[i] != NULL)
	{
		check = ft_strncmp(envp[i], "PATH=", 5);
		if (check == 0)
		{
			tmp = ft_split(envp[i] + 5, ':');
			break;
		}
		i++;
	}
	master->path = tmp;
	return ;
}

void	fork_cmds(t_parent *master)
{
	int		i;
	int		pid;
	int		pipefd[2];
	int		check;
	t_node	*current;

	i = 0;
	pid = 0;
	check = 0;
	current = master->in->next;
	while (current != master->out && i < master->cmds)
	{
		check = pipe(master->mfds->pipefd[i]);
		if (check == -1)
		{
			master->fds->pipefd[i][0] = -1;
			master->fds->pipefd[i][1] = -1;
			master->fds->fdstate[i] = 1;
		}
		pid = fork();
		if (pid == -1)
			error_exit("fork", master);
		else if (pid == 0)
		{
			run_childs(master);
			return ;
		}
		current->pid = pid;
		current = current->next;
		i++;
	}
	return ;
}

void	close_and_wait(t_parent *master)
{
	int		i;
	t_node	*current;

	i = 0;
	while (i < master->cmds - 1)
	{
		close(master->fds->pipefd[i][0]);
		close(master->fds->pipefd[i][1]);
		i++;
	}
	i = 0;
	current = master->in->next;
	while (i < master->cmds)
	{
		waitpid(current->pid, NULL, 0);
		current = current->next;
		i++;
	}
	return ;
}
