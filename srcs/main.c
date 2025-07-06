/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:26 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/07/06 19:18:14 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_structs	*var;

	format_check(argc);
	init_structs(&var, argv);
	init_var(var);
	check_path(var, envp);
	start_childs(var);
	exec_childs(var, argv, envp);
	free_all(var);
	return (0);
}
