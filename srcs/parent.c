#include "pipex.h"

void	check_argc(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("usage:./pipex infile \"cmd1 -op\" \"cmd2 -op\" outfile", 2);
		error_exit("argc", NULL);
	}
	return ;
}

void	make_list(int argc, char **argv, t_parent *master)
{
	t_node	*tmp;
	int		i;

	tmp = master->arg_head;
	i = 0;
	while (i < argc && tmp->next != master->arg_head)
	{
		tmp->next = ft_calloc(sizeof(t_node), 1);
		if (tmp->next == NULL)
			error_exit("calloc", NULL);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp->next = master->arg_head;
	master->arg_head->prev = tmp
	return ;
}

void	place_args(int argc, char **argv, t_parent *master)
{
	int		i;
	t_node	tmp;

	i = 0;
	tmp = master->arg_head
	while (i < argc)
	{
		tmp->value = argv[i];
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	return ;
}

void	split_env(char **envp, t_parent *master)
{
	int		i;
	char	**tmp;

	i = 0;
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

void	make_pipes(int argc, t_parent *master)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = master->pipe_head;
	while (i < argc)
	{
		if (i > 1 && i < (argc - 1))
		{
			check = pipe(tmp->pipefd);
			if (check == -1)
				error_exit("pipe", master);
		}
		tmp = tmp->next;
		i++;
	}
	return ;
}

void	open_check(int argc, t_parent *master)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = master->arg_head;
	while (i < argc)
	{
		if (tmp->index == 1|| tmp->index == (argc - 1))
			tmp->exit_code = open(tmp->value);
		tmp = tmp->next;
		i++;
	}
	return ;
}

void	access_check(int argc ,t_parent *master)
{
	int		num;
	int		i;
	t_node	tmp;

	i = 0;
	num = argc - 3;
	tmp	= master->in->next;
	while (i < num)
	{
		tmp->valid = find_cmd(tmp->cmd[0], master->path);
		tmp = tmp->next;
		i++;
	}
	return ;
}

int		find_cmd(char *cmd, char **path)
{
	while (path[i] != NULL)
	{
		base = ft_strjoin(path[i], "/");
		fullpath = ft_strjoin(base, cmd);
		free(base);
		check = access(fullpath, X_OK);
		free(fullpath);
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}

void	start_child(t_parent *master, int pid)
{
	if (master == NULL)
		erorr_exit("NULL", master);
	pid = fork();
	if (pid == -1)
		error_exit("fork", master);
	else if (pid == 0)
		step_child(master);
	return ;
}
