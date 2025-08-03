#include "pipex.h"

int		main(int argc, char **argv, char **envp)
{
	t_parent	*master;
	int			exitcode;

	exitcode = 0;
	master = NULL;
	//check_argc(argc);
	init_parent(argc, &master);
	make_list(master);
	place_args(argc, argv, master);
	split_env(envp, master);
	make_procs(master);
	exitcode = wait_childs(master);
	free_all(master);
	return (exitcode);
}
