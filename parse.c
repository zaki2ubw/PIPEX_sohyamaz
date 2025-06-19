#include "pipex.h"

void	parce_args(t_cmd *cmd, char **cmd, char *path)
{
	char	**dir;
	
	dir = ft_split(path, ':');
	if (dirs == NULL)
		error_exit(ERR_SPLIT_FAILED);
		
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

char	*get_path(t_cmd *cmd, char **dirs)
{
	char	*path;
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while(dirs[count] != NULL)
	{
		flag = ft_strncmp(dirs[count], "$PATH=", 6);
		if (flag == 0)
		{
			path = dirs[count];
			return (path);
		}
		count++;
	}
	return (NULL);			
}

void	parce_cmd(t_cmd *cmd, char **argv, char **envp)
{
	char	**dirs;
	char	*cmd1;
	char	*cmd2;
	char	*path;
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	path = get_path(dirs);
	cmd1 = ft_split(argv[2], ' ');
	if (dirs == NULL)
		error_exit(ERR_SPLIT_FAILED);
	cmd2 = ft_split(argv[3], ' ');
	if (dirs == NULL)
		error_exit(ERR_SPLIT_FAILED);
	
