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

	tmp = master->head;
	i = 0;
	while (i < argc && tmp->next != master->head)
	{
		tmp->next = ft_calloc(sizeof(t_node), 1);
		if (tmp->next == NULL)
			error_exit("calloc", NULL);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp->next = master->head;
	master->head->prev = tmp
	return ;
}

void	place_args(int argc, char **argv, t_parent *master)
{
	int		i;
	t_node	tmp;

	i = 0;
	tmp = master->head
	while (i < argc)
	{
		tmp->arg = argv[i];
		tmp->num = i;
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

void	make_pipe(int argc, t_parent *master)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = master->head;
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
	tmp = master->head;
	while (i < argc)
	{
		if (i == 1 || i == (argc - 1))
			tmp->exec_status = open(tmp->arg);
		tmp = tmp->next;
		i++;
	}
	return ;
}

