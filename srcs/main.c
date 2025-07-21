#include "pipex.h"

int		main(int argc, char **argv, char **envp)
{
	t_parent	*master;

	&master = ft_calloc(sizeof(t_parent **), 1);
	master->head_ = ft_calloc(sizeof(t_node), 1);
	//check	:is argc = 5?
	check_argc(argc);
	//place	:all args into the list
	make_list(argc, argv);
	//split	:cut off envp
	//find	:search if envp has "path"? and put it into *path
	//pipe	:generate a pipe;
	//fork	:generate 2 childs
	//open	:exec open and validate in/outfile
	//join	:concatenate path and cmds
	//check	:validate cmd with access
	//dup2	:connect pipefd to stdin/out
	//wait	:close fd and wait childs
	//exec	:exec cmds in child process
	//free	:exit sequence in parent process
	//return
}
