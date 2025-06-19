#include "pipex.h"

void	parce_args(t_cmd *cmd, char **cmd, char ***dirs)
{
	while(dir[count] != NULL)
	{
		dir = ft_split(dirs[count], ' ');
		if (dir == NULL)
			error_exit(ERR_ARROCATE_FAILED);
		path = ft_strjoin(dir[2], "/");
		path = ft_strjoin(path, cmd[0]);
		flag = access(path, X_OK);
		if (flag == 0)
			break ;
		count++;	
}

void	parce_cmd(t_cmd *cmd, char **argv, char **envp)
{
	char	**dirs;
	char	*cmd1;
	char	*cmd2;
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	dirs = ft_split(envp, ':');
	if (dirs == NULL)
		error_exit(ERR_SPLIT_FAILED);
	cmd1 = ft_split(argv[2], ' ');
	if (dirs == NULL)
		error_exit(ERR_SPLIT_FAILED);
	cmd2 = ft_split(argv[3], ' ');
	if (dirs == NULL)
		error_exit(ERR_SPLIT_FAILED);
	
