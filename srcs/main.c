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
	place_args(argc, argv, *master)
	//split	:cut off envp
	//find	:search if envp has "path"? and put it into *path
	split_env(envp, *master);
	//pipe	:generate a pipe;
	make_pipe(argc, *master);
	//open	:exec open and validate in/outfile
	open_check(argc, *master);
	//fork	:generate 2 childs
	start_child(master->in->pid, *master);
	start_child(master->out->pid, *master);
	//join	:concatenate path and cmds
	//check	:validate cmd with access
	//dup2	:connect pipefd to stdin/out
	//wait	:close fd and wait childs
	//exec	:exec cmds in child process
	//free	:exit sequence in parent process
	//return
}


int	old_main(int argc, char **argv, char **envp)
{
	t_structs	*var;

	//format_check(argc);
	if (argc != 5)
	{
		ft_putstr_fd("usage:./pipex infile \"cmd1 -op\" \"cmd2 -op\" outfile",2);
		exit(ERR_BAD_FORMAT);
	}
	//init_structs(&var, argv);
	*var = ft_calloc(sizeof(t_structs), 1);
	if (*var == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->cmd = ft_calloc(sizeof(t_cmd), 1);
	if ((*var)->cmd == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->path = ft_calloc(sizeof(t_path), 1);
	if ((*var)->path == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->fd = ft_calloc(sizeof(t_fd), 1);
	if ((*var)->fd == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->ps = ft_calloc(sizeof(t_proc), 1);
	if ((*var)->ps == NULL)
		error_exit(var, ERR_ALLOCATE_FAILED);
	(*var)->cmd->infile = argv[1];
	(*var)->cmd->cmd1 = argv[2];
	(*var)->cmd->cmd2 = argv[3];
	(*var)->cmd->outfile = argv[4];
	//init_var(var);
	var->fd->fd_in = open(var->cmd->infile, O_RDONLY);
	if (var->fd->fd_in == -1)
		error_exit(&var, ERR_OPEN_FAILED);
	var->fd->fd_out = open(var->cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var->fd->fd_out == -1)
		error_exit(&var, ERR_OPEN_FAILED);
	flag = pipe(var->fd->pipefd);
	if (flag == -1)
		error_exit(&var, ERR_PIPE_FAILED);
	//check_path(var, envp);
	while (envp[count] != NULL)
	{
		skip = ft_strncmp(envp[count], "PATH=", 5);
		if (skip == 0)
			break ;
		count++;
	}
	if (envp[count] == NULL)
		error_exit(&var, ERR_PATH_NOT_FOUND);
	var->path->dirs = ft_split(envp[count] + 5, ':');
	if (var->path->dirs == NULL)
		error_exit(&var, ERR_SPLIT_FAILED);
	//start_childs(var);
	var->ps->pid1 = fork();
	if (var->ps->pid1 == -1)
		error_exit(&var, ERR_FORK_FAILED);
	if (var->ps->pid1 == 0)
		return ;
	var->ps->pid2 = fork();
	if (var->ps->pid2 == -1)
		error_exit(&var, ERR_FORK_FAILED);
	if (var->ps->pid2 == 0)
		return ;
	//exec_childs(var, argv, envp);
	if (var->ps->pid1 == 0)
		exec_first_cmd(var, envp);
		childs_dup(var->fd->fd_in, STDIN_FILENO);
		childs_dup(var->fd->pipefd[1], STDOUT_FILENO);
		close_childs_fd(var->fd->pipefd[0]);
		close_childs_fd(var->fd->pipefd[1]);
		var->path->cmd1 = ft_split(var->cmd->cmd1, ' ');
	if (var->path->cmd1 == NULL)
		exit(ERR_SPLIT_FAILED);
	var->path->fullpath1 = check_cmd(var, var->path->cmd1[0]);
	//check_cmd
		tmp = ft_strchr(cmd, '/');
		if (tmp != NULL)
			tmp = access_check(cmd);
				//access_check
				check = access(cmd, X_OK);
				if (check == -1)
					return (NULL);
				full = ft_strdup(cmd);
				if (full == NULL)
					return (NULL);
		else
			tmp = find_path(var, cmd);
		//find_path
				while (var->path->dirs[count] != NULL)
				{
					tmp = ft_strjoin(var->path->dirs[count], "/");
					full = ft_strjoin(tmp, cmd);
					check = access(full, X_OK);
					free(tmp);
					if (check == 0)
						return (full);
					free(full);
					count++;
				}
	if (var->path->fullpath1 == NULL)
	{
		perror("access");
		free_all(var);
		exit (ERR_INVALID_CMD);
	}
	execve(var->path->fullpath1, var->path->cmd1, envp);
	perror("execve");
	free_all(var);
	exit(127);
	if (var->ps->pid2 == 0)
		exec_second_cmd(var, envp);
	//close_parent_fd(var, var->fd->pipefd[0]);
	//close_parent_fd(var, var->fd->pipefd[1]);
	//waitpid(var->ps->pid1, NULL, 0);
	//waitpid(var->ps->pid2, NULL, 0);
	free_all(var);
	return (0);
}
