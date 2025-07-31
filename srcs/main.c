#include "pipex.h"

int		main(int argc, char **argv, char **envp)
{
	t_parent	*master;
	int			exitcode;

	exitcode = 0;
	master = ft_calloc(sizeof(t_parent), 1);
	master->arg_head = ft_calloc(sizeof(t_node), 1);
	//check	:is argc = 5?
	check_argc(argc, master);
	//place	:all args into the list
	make_list(argc, argv);
	place_args(argc, argv, master)
	//split	:cut off envp
	//find	:search if envp has "path"? and put it into *path
	split_env(envp, master);
	fork_cmds(master);
	close_and_wait(master);
	exitcode = master->out->prev->exitcode;
	free_all(master);
	return (exitcode);
}
