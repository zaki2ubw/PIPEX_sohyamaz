#include "pipex.h"

void	dup_childs(int argc, t_parent *master)
{
		int		num;
		int		i;
		t_node *tmp;

	num = argc - 1;
	i = 0;
