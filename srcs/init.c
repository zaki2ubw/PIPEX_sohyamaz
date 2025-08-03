#include "pipex.h"

void	check_argc(int argc, t_parent *master)
{
	if (argc != 5)
	{
		ft_putstr_fd("usage:./pipex infile \"cmd1 -op\" \"cmd2 -op\" outfile\n", 2);
		error_exit("argc", NULL);
	}
	return ;
}

void	init_parent(t_parent **master)
{
	*master = ft_calloc(sizeof(t_parent), 1);
	if (*master == NULL)
		error_exit("ft_calloc", NULL);
	(*master)->in = ft_calloc(sizeof(t_node), 1);
	if ((*master)->in == NULL)
		error_exit("ft_calloc", *master);
	(*master)->cmds = argc - 3;
	return ;
}

void	make_list(int argc, t_parent *master)
{
	t_node	*current;
	int		i;

	current = master->in;
	i = 2;
	while (i < (argc - 2))
	{
		current->next = ft_calloc(sizeof(t_node), 1);
		if (current->next == NULL)
			error_exit("ft_calloc", master);
		current->next->prev = current;
		current = current->next;
		i++;
	}
	master->out = current;
	current->next = NULL;
	return ;
}

void	place_args(int argc, char **argv, t_parent *master)
{
	int		i;
	t_node	*current;

	i = 1;
	current = master->in;
	while (i < argc && current != NULL)
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
	master->envp = envp;
	return ;
}
