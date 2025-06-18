/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:26 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/17 21:39:08 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

typedef struct s_cmd
{
	char	*cmd;
	int		fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipe
{
	int		fd[2];
	struct s_pipe	*prev;
	struct s_pipe	*next;
}	t_pipe;
int	main(int argc, char **argv, char **envp)
{
	format_check(argc);
	//allocate pipe < argc - 3 times
	//open fd for in/out
	//fork process < argc - 3 times
	//while(--argc - 3 > 0) check cmd path in fork prosess
	//check previllage infile/outfile
	//close fd
	//wait pid
	//execute cmds in fork prosess
	//free all
	return (0);
}
