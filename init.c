/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:11:56 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/17 22:20:54 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_pipe(t_cmd *cmd, int argc)
{
	int		count;
	int		flag;
	t_cmd	*current;

	current = cmd
	while (count < argc - 4)
	{
		flag = pipe(current->fd);
		if 	(flag == -1)
			error_exit(ERR_PIPE_FAILED);
		current = current->next;
		count++;
	}
	return ;
}

void	init_cmd(t_cmd **cmd);
{
	if (cmd == NULL)
		error_exit(ERR_NULL_VALUE_DETECTED);
	*cmd = ft_calloc(sizeof(t_cmd), 1);
	if (*cmd == NULL)
		error_exit(ERR_ALLOCATE_FAILED);
	(*cmd)->prev = *cmd;
	(*cmd)->next = *cmd;
	return ;
}
