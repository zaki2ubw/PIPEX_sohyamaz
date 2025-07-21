#include "pipex.h"

void	error_exit(char *error, t_parent *master)
{
	perror(error);
	//free_all
	exit (1);
}
